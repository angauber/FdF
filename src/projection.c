/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   projection.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 18:01:32 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 18:34:18 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fill_line_para(t_line *line, t_param *param, t_dot dot1, t_dot dot2)
{
	line->x0 = param->factor * dot1.x + param->x;
	line->y0 = param->factor * dot1.y + param->y;
	line->x1 = param->factor * dot2.x + param->x;
	line->y1 = param->factor * dot2.y + param->y;
}

void	calculate_line(t_param *param, t_dot dot1, t_dot dot2)
{
	t_line		line;
	t_2d_dot	polar;
	double		rad;

	rad = 26.565 * (M_PI / 180);
	mult_matrix(param->matrix, &dot1, &dot2);
	if (param->proj == 0)
	{
		line.x0 = param->factor * (dot1.x - dot1.y) * cos(rad) + param->x;
		line.y0 = param->factor * ((dot1.x + dot1.y) * sin(rad) - dot1.z)
		+ param->y;
		line.x1 = param->factor * (dot2.x - dot2.y) * cos(rad) + param->x;
		line.y1 = param->factor * ((dot2.x + dot2.y) * sin(rad) - dot2.z)
		+ param->y;
	}
	else
		fill_line_para(&line, param, dot1, dot2);
	polar = (t_2d_dot){.x = param->map->zmin, .y = param->map->zmax};
	if ((line.x0 >= 0 && line.x0 <= 1600) && (line.y0 >= 0 && line.y0 <= 900)
	&& (line.x1 >= 0 && line.x1 <= 1600) && (line.y1 >= 0 && line.y1 <= 900))
		draw_line_antialias(param, line, create_color(dot1.z > dot2.z ?
		dot1.z : dot2.z, polar, param->hue, 50));
}
