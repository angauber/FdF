/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 18:27:22 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 17:42:30 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void	count_lines(t_map *map, int fd)
{
	char *line;
	int i;
	
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	map->x = i;
}

int		count_numbers(t_map *map, char *line)
{
	int i;
	int j;
	
	i = -1;
	j = 0;
	while (line[++i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') && (i == 0 || line[i - 1] == ' '))
		{
			j++;
			while (line[i] >= '0' && line[i] <= '9')
				i++;
		}
	}
	map->y = j;
	return (j);
} 

int		*parse_line(t_map *map, char *line)
{
	int		*current;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if ((current = malloc(sizeof(int) * count_numbers(map, line))) == NULL)
		return (NULL);
	while (line[++i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') && (i == 0 || line[i - 1] == ' '))
		{
			current[j] = ft_atoi(&(line[i]));
			j++;	
		}
	}
	return (current);
}

void	parse_map(int fd, char *file, char *line)
{
	t_map	*map;
	int		i;

	i = 0;
	if ((map = malloc(sizeof(t_map))) == NULL)
		return ;
	count_lines(map, fd);
	fd = open(file, O_RDONLY);
	if ((map->table = malloc(sizeof(int*) * map->x)) == NULL)
		return ;
	while (get_next_line(fd, &line) != 0)
	{
		map->table[i] = parse_line(map, line);
		i++;
	}
	render_map(map);
}

int		main(int ac, char **av)
{
	int 	fd;
	char	*line;

	line = NULL;
	if (ac != 2)
	{
		ft_printf("Usage: ./fdf map\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd != -1)
		parse_map(fd, av[1], line);
	else
	{
		ft_printf("Wrong map format\n");
	}
	return (0);
}