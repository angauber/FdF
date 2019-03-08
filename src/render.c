/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/07 13:31:45 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 18:44:08 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

t_rgb	create_color(int color)
{
	t_rgb rgb;
	
	rgb.r = color / 65536;
	rgb.g = (color / 256) % 256;;
	rgb.b = color % 256;
	return (rgb);
}

void	mult_matrix(double **mat, t_dot *dot1, t_dot *dot2)
{
	t_dot new1;
	t_dot new2;

	new1.x = (dot1->x * mat[0][0]) + (dot1->y * mat[0][1]) + (dot1->z * mat[0][2]);
	new1.y = (dot1->x * mat[1][0]) + (dot1->y * mat[1][1]) + (dot1->z * mat[1][2]);
	new1.z = (dot1->x * mat[2][0]) + (dot1->y * mat[2][1]) + (dot1->z * mat[2][2]);
	
	new2.x = (dot2->x * mat[0][0]) + (dot2->y * mat[0][1]) + (dot2->z * mat[0][2]);
	new2.y = (dot2->x * mat[1][0]) + (dot2->y * mat[1][1]) + (dot2->z * mat[1][2]);
	new2.z = (dot2->x * mat[2][0]) + (dot2->y * mat[2][1]) + (dot2->z * mat[2][2]);
	
	dot1->x = new1.x;
	dot1->y = new1.y;
	dot1->z = new1.z;
	
	dot2->x = new2.x;
	dot2->y = new2.y;
	dot2->z = new2.z;
}

void	rotation_matrix(char axe, double rad, t_dot *dot1, t_dot *dot2)
{
	double **mat;
	int i;

	i = -1;
	if ((mat = malloc(sizeof(double *) * 3)) == NULL)
		return ;
	while (++i < 3)
	{
		if ((mat[i] = malloc(sizeof(double) * 3)) == NULL)
			return ;
	}
	if (axe == 'x')
	{
		mat[0][0] = 1;
		mat[0][1] = 0;
		mat[0][2] = 0;
		
		mat[1][0] = 0;
		mat[1][1] = cos(rad);
		mat[1][2] = -sin(rad);
		
		mat[2][0] = 0;
		mat[2][1] = sin(rad);
		mat[2][2] = cos(rad);
	}
	if (axe == 'y')
	{
		mat[0][0] = cos(rad);
		mat[0][1] = 0;
		mat[0][2] = sin(rad);
		
		mat[1][0] = 0;
		mat[1][1] = 1;
		mat[1][2] = 0;
		
		mat[2][0] = -sin(rad);
		mat[2][1] = 0;
		mat[2][2] = cos(rad);
	}
	if (axe == 'z')
	{
		mat[0][0] = cos(rad);
		mat[0][1] = -sin(rad);
		mat[0][2] = 0;

		mat[1][0] = sin(rad);
		mat[1][1] = cos(rad);
		mat[1][2] = 0;

		mat[2][0] = 0;
		mat[2][1] = 0;
		mat[2][2] = 1;
	}
	mult_matrix(mat, dot1, dot2);
}

void	draw_axes(t_mlx mlx, t_vector vec)
{
	t_line lineI;
	t_line lineJ;
	t_line lineK;

	lineI.x0 = 200;
	lineI.y0 = 200;
	lineI.x1 = 200 + (vec.ix * 5);
	lineI.y1 = 200 + (vec.iy * 5);

	lineJ.x0 = 200;
	lineJ.y0 = 200;
	lineJ.x1 = 200 + (vec.jx * 5);
	lineJ.y1 = 200 + (vec.jy * 5);


	lineK.x0 = 200;
	lineK.y0 = 200;
	lineK.x1 = 200 + (vec.kx * 5);
	lineK.y1 = 200 + (vec.ky * 5);
	
	draw_line_antialias(mlx, lineI, create_color(0x00ad48));	
	draw_line_antialias(mlx, lineJ, create_color(0x0817b2));	
	draw_line_antialias(mlx, lineK, create_color(0xc90086));	
}

void	calculate_line(t_mlx mlx, t_dot *dot1, t_dot *dot2)
{
	t_line line;
	t_vector vec;
//	t_ortho proj;
	int		omega;
	int		alpha;
	double	factor;

	factor = 0.6;
	vec = (t_vector){.ix = 10 * factor, .iy = 0, .jx = 0, .jy = -10 * factor, .kx = -0.6 * factor, .ky = 0.6 * factor};
	
	draw_axes(mlx, vec);
	
//	omega = 45;
//	alpha = 35;

//	ft_printf("%d %d %d-> ", dot1->x, dot1->y, dot1->z);
	rotation_matrix('x', -90 * (3.14159265358979323846 / 180), dot1, dot2);
//	ft_printf("%d %d %d\n", dot1->x, dot1->y, dot1->z);
/*
i .x = 10
	.y = 0
	
j .x = 0
	.y = -10
	
k .x = -5
	.y = 5


i = reper vectoriel;
c = point parser;

x = (i.x * c.x) + (j.x * c.y) + (k.x * c.z);
y = (i.y * c.x) + (j.y * c.y) + (k.y * c.z);
*/
	line.x0 = ((vec.ix * dot1->x) + (vec.jx * dot1->y) + (vec.kx * dot1->z)) + 300;
	line.y0 = ((vec.iy * dot1->x) + (vec.jy * dot1->y) + (vec.ky * dot1->z)) + 700;
	
	line.x1 = ((vec.ix * dot2->x) + (vec.jx * dot2->y) + (vec.kx * dot2->z)) + 300;
	line.y1 = ((vec.iy * dot2->x) + (vec.jy * dot2->y) + (vec.ky * dot2->z)) + 700;

/*	proj = (proj){.A1 = cos(omega), .A2 = sin(omega), .B1 = cos(alpha), .B2 = sin(alpha), .x = 600, .y = 400};

	line.x0 = proj.x + factor * ((proj.A1 * dot1->x) + (proj.A2 * dot1->y));
	line.y0 = proj.y + factor * (proj.B2 * ((proj.A2 * dot1->x) - (proj.A1 * dot1->y)) + proj.B1 * dot1->z);

	line.x1 = proj.x + factor * ((proj.A1 * dot2->x) + (proj.A2 * dot2->y));
	line.y1 = proj.y + factor * (proj.B2 * ((proj.A2 * dot2->x) - (proj.A1 * dot2->y)) + proj.B1 * dot2->z);

	ft_printf("x0: %d y0: %d	x1: %d y1: %d\n", line.x0, line.y0, line.x1, line.y1);
*/	if ((line.x0 >= 0 && line.x0 <= 1600) && (line.x1 >= 0 && line.x1 <= 1600) && (line.y0 >= 0 && line.y0 <= 900) && (line.y1 >= 0 && line.y1 <= 900))
		draw_line_antialias(mlx, line, create_color(0x2D7EFF));
}

void	render_map(t_map *map)
{
	int		x;
	int		y;
	t_mlx	mlx;
	t_dot	*dot1;
	t_dot	*dot2;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1600, 900, "FdF");
	x = -1;
	while (++x < map->x)
	{
		y = -1;
		while (++y < map->y - 1)
		{
			dot1->x = y;
			dot1->y = x;
			dot1->z = map->table[x][y];

			dot2->x = (y + 1);
			dot2->y = x;
			dot2->z = map->table[x][y + 1];
			calculate_line(mlx, dot1, dot2);
		}
	}
	x = -1;
	while (++x < map->x - 1)
	{
		y = -1;
		while (++y < map->y)
		{
			dot1->x = y;
			dot1->y = x;
			dot1->z = map->table[x][y];
			
			dot2->x = y;
			dot2->y = (x + 1);
			dot2->z = map->table[x + 1][y];
			calculate_line(mlx, dot1, dot2);
		}
	}
	mlx_loop(mlx.mlx_ptr);
}
