/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   xiaolin_wu.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:48:58 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 16:28:33 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	init_wu_x(t_param *param, t_xiaolin *wu, t_line line)
{
	wu->gradient = wu->dy / wu->dx;
	wu->xend = ROUND_(line.x0);
	wu->yend = line.y0 + wu->gradient * (wu->xend - line.x0);
	wu->xgap = RFPART_(line.x0 + 0.5);
	wu->xpxl1 = wu->xend;
	wu->ypxl1 = IPART_(wu->yend);
	plot(param, wu->xpxl1, wu->ypxl1, RFPART_(wu->yend) * wu->xgap);
	plot(param, wu->xpxl1, wu->ypxl1 + 1, FPART_(wu->yend) * wu->xgap);
}

void	draw_x_front(t_param *param, t_line line, t_xiaolin wu)
{
	int x;

	if (line.x1 < line.x0)
	{
		SWAP_(line.x0, line.x1);
		SWAP_(line.y0, line.y1);
	}
	init_wu_x(param, &wu, line);
	wu.inter = wu.yend + wu.gradient;
	wu.xend = ROUND_(line.x1);
	wu.yend = line.y1 + wu.gradient * (wu.xend - line.x1);
	wu.xgap = FPART_(line.x1 + 0.5);
	wu.xpxl2 = wu.xend;
	wu.ypxl2 = IPART_(wu.yend);
	plot(param, wu.xpxl2, wu.ypxl2, RFPART_(wu.yend) * wu.xgap);
	plot(param, wu.xpxl2, wu.ypxl2 + 1, FPART_(wu.yend) * wu.xgap);
	x = wu.xpxl1;
	while (++x < wu.xpxl2)
	{
		plot(param, x, IPART_(wu.inter), RFPART_(wu.inter));
		plot(param, x, IPART_(wu.inter) + 1, FPART_(wu.inter));
		wu.inter += wu.gradient;
	}
}

void	init_wu_y(t_param *param, t_xiaolin *wu, t_line line)
{
	wu->gradient = wu->dx / wu->dy;
	wu->yend = ROUND_(line.y0);
	wu->xend = line.x0 + wu->gradient * (wu->yend - line.y0);
	wu->ygap = RFPART_(line.y0 + 0.5);
	wu->ypxl1 = wu->yend;
	wu->xpxl1 = IPART_(wu->xend);
	plot(param, wu->xpxl1, wu->ypxl1, RFPART_(wu->xend) * wu->ygap);
	plot(param, wu->xpxl1 + 1, wu->ypxl1, FPART_(wu->xend) * wu->ygap);
}

void	draw_y_front(t_param *param, t_line line, t_xiaolin wu)
{
	int y;

	if (line.y1 < line.y0)
	{
		SWAP_(line.x0, line.x1);
		SWAP_(line.y0, line.y1);
	}
	init_wu_y(param, &wu, line);
	wu.inter = wu.xend + wu.gradient;
	wu.yend = ROUND_(line.y1);
	wu.xend = line.x1 + wu.gradient * (wu.yend - line.y1);
	wu.ygap = FPART_(line.y1 + 0.5);
	wu.ypxl2 = wu.yend;
	wu.xpxl2 = IPART_(wu.xend);
	plot(param, wu.xpxl2, wu.ypxl2, RFPART_(wu.xend) * wu.ygap);
	plot(param, wu.xpxl2 + 1, wu.ypxl2, FPART_(wu.xend) * wu.ygap);
	y = wu.ypxl1;
	while (++y < wu.ypxl2)
	{
		plot(param, IPART_(wu.inter), y, RFPART_(wu.inter));
		plot(param, IPART_(wu.inter) + 1, y, FPART_(wu.inter));
		wu.inter += wu.gradient;
	}
}

void	draw_line_antialias(t_param *param, t_line line, t_rgb rgb)
{
	t_xiaolin	wu;

	param->rgb = rgb;
	wu.dx = (double)line.x1 - (double)line.x0;
	wu.dy = (double)line.y1 - (double)line.y0;
	if (fabs(wu.dx) > fabs(wu.dy))
		draw_x_front(param, line, wu);
	else
		draw_y_front(param, line, wu);
}
