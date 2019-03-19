/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hsv_to_rgb.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 17:00:14 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 17:21:50 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

t_rgb	create_color(int current, t_2d_dot polar, int start, int range)
{
	double	hue;

	hue = (((((double)current - (double)polar.x) / ((double)polar.y
	- (double)polar.x)) * 100) * range) / 100;
	return (create_from_hsv(start + hue, 0.73, 0.96));
}

t_rgb	create_from_hsv(double h, double s, double v)
{
	int		i;
	t_hsv	hsv;
	t_rgb	rgb;
	t_dot	dot;

	h /= 60;
	i = (int)trunc(h);
	hsv.f = h - i;
	hsv.p = v * (1.0 - s);
	hsv.q = v * (1.0 - (s * hsv.f));
	hsv.t = v * (1.0 - (s * (1.0 - hsv.f)));
	if (i == 0)
		dot = (t_dot){.x = v, .y = hsv.t, .z = hsv.p};
	else if (i == 1)
		dot = (t_dot){.x = hsv.q, .y = v, .z = hsv.p};
	else if (i == 2)
		dot = (t_dot){.x = hsv.p, .y = v, .z = hsv.t};
	else if (i == 3)
		dot = (t_dot){.x = hsv.p, .y = hsv.q, .z = v};
	else if (i == 4)
		dot = (t_dot){.x = hsv.t, .y = hsv.p, .z = v};
	else
		dot = (t_dot){.x = v, .y = hsv.p, .z = hsv.q};
	rgb = (t_rgb){.r = dot.x * 255, .g = dot.y * 255, .b = dot.x * 255};
	return (rgb);
}
