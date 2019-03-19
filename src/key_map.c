/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_map.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 17:48:06 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 18:09:34 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void	key_part_0(int key, t_param *param)
{
	if (key == 12)
		param->angz += 4;
	else if (key == 14)
		param->angz -= 4;
	else if (key == 13)
		param->angx += 4;
	else if (key == 1)
		param->angx -= 4;
	else if (key == 2)
		param->angy += 4;
	else if (key == 0)
		param->angy -= 4;
	else if (key == 78)
		param->factor *= 0.8;
	else if (key == 69)
		param->factor *= 1.2;
}

void	key_part_1(int key, t_param *param)
{
	if (key == 15)
		param->scale += 0.02;
	else if (key == 3)
		param->scale -= 0.02;
	else if (key == 123)
		param->x -= 10;
	else if (key == 124)
		param->x += 10;
	else if (key == 125)
		param->y += 10;
	else if (key == 126)
		param->y -= 10;
	else if (key == 43 && param->hue < 350)
		param->hue += 10;
	else if (key == 47 && param->hue > 10)
		param->hue -= 10;
}

int		key_press(int key, t_param *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx.mlx_ptr, param->mlx.win_ptr);
		exit(0);
	}
	else if (key == 12 || key == 14 || key == 13 || key == 1 || key == 0 ||
	key == 2 || key == 78 || key == 69 || key == 15 || key == 3 || key == 123
	|| key == 124 || key == 125 || key == 126 || key == 43 || key == 47)
	{
		mlx_destroy_image(param->mlx.mlx_ptr, param->img);
		mlx_clear_window(param->mlx.mlx_ptr, param->mlx.win_ptr);
		key_part_0(key, param);
		key_part_1(key, param);
		render_all_points(param);
	}
	return (0);
}
