/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/07 13:31:45 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 18:35:08 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "stdio.h"

void	render_all_points(t_param *param)
{
	int x;
	int y;
	t_dot	dot1;
	t_dot	dot2;

	rotate_matrix(param);
	param->img = mlx_new_image(param->mlx.mlx_ptr, 1600, 900);
	param->addr = (int *)mlx_get_data_addr(param->img, &b, &s, &e);
	x = -1;
	while (++x < param->map->x)
	{
		y = -1;
		while (++y < param->map->y - 1)
		{
			dot1.x = y - (param->map->y / 2);
			dot1.y = x - (param->map->x / 2);
			dot1.z = param->map->table[x][y] * param->scale;

			dot2.x = (y + 1) - (param->map->y / 2);
			dot2.y = x - (param->map->x / 2);
			dot2.z = param->map->table[x][y + 1] * param->scale;
			calculate_line(param, dot1, dot2);
		}
	}
	x = -1;
	while (++x < param->map->x - 1)
	{
		y = -1;
		while (++y < param->map->y)
		{
			dot1.x = y - (param->map->y / 2);
			dot1.y = x - (param->map->x / 2);
			dot1.z = param->map->table[x][y] * param->scale;

			dot2.x = y - (param->map->y / 2);
			dot2.y = (x + 1) - (param->map->x / 2);
			dot2.z = param->map->table[x + 1][y] * param->scale;
			calculate_line(param, dot1, dot2);
		}
	}
	mlx_put_image_to_window(param->mlx.mlx_ptr, param->mlx.win_ptr, param->img, 0, 0);
}

void	render_map(t_map *map)
{
	t_param	params;
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1600, 900, "FdF");
	params.angx = 0;
	params.angy = 0;
	params.angz = 0;
	params.scale = 1;
	params.factor = 20;
	params.x = 800;
	params.y = 450;
	params.hue = 100;
	params.mlx = mlx;
	params.map = map;
	params.proj = 0;
	mlx_hook(mlx.win_ptr, 2, 0, key_press, &params);
	render_all_points(&params);
	mlx_loop(mlx.mlx_ptr);
}
