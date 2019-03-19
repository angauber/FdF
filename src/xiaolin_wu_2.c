/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   xiaolin_wu_2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 12:04:27 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 16:20:26 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	change_brightness(t_rgb *rgb, float c)
{
	rgb->r = c * rgb->r;
	rgb->g = c * rgb->g;
	rgb->b = c * rgb->b;
}

int		rgb_to_int(t_rgb *rgb)
{
	return (65536 * rgb->r + 256 * rgb->g + rgb->b);
}

void	int_to_rgb(t_rgb *rgb, int nb)
{
	rgb->r = nb / 65536;
	rgb->g = (nb / 256) % 256;
	rgb->b = nb % 256;
}

void	plot(t_param *param, int x, int y, float c)
{
	t_rgb rgb;

	rgb.r = param->rgb.r;
	rgb.g = param->rgb.g;
	rgb.b = param->rgb.b;
	change_brightness(&rgb, c);
	if ((y * 1600 + x) > 0 && (y * 1600 + x) < 1440000)
		param->addr[y * 1600 + x] = rgb_to_int(&rgb);
}
