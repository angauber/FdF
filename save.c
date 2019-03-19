/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 10:44:30 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 13:45:10 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line_antialias(t_param *param, t_line line, t_rgb rgb)
{
	double	dx; 
	double	dy;
    double gradient;
    double xend;
    double yend;
    double xgap;
    double ygap;
    double intery;
    double interx;
    int     xpxl1;
    int     ypxl1;
    int     xpxl2;
    int     ypxl2;
    int     x;
    int     y;

    dx = (double)line.x1 - (double)line.x0;
    dy = (double)line.y1 - (double)line.y0;
	if (fabs(dx) > fabs(dy))
    {
		if (line.x1 < line.x0)
        {
			SWAP_(line.x0, line.x1);
			SWAP_(line.y0, line.y1);
		}
		gradient = dy / dx;
		xend = ROUND_(line.x0);
		yend = line.y0 + gradient*(xend - line.x0);
		xgap = RFPART_(line.x0 + 0.5);
		xpxl1 = xend;
		ypxl1 = IPART_(yend);
		plot(param, rgb, xpxl1, ypxl1, RFPART_(yend) * xgap);
		plot(param, rgb, xpxl1, ypxl1 + 1, FPART_(yend) * xgap);
		intery = yend + gradient;

		xend = ROUND_(line.x1);
		yend = line.y1 + gradient*(xend - line.x1);
		xgap = FPART_(line.x1 + 0.5);
		xpxl2 = xend;
		ypxl2 = IPART_(yend);
		plot(param, rgb, xpxl2, ypxl2, RFPART_(yend) * xgap);
		plot(param, rgb, xpxl2, ypxl2 + 1, FPART_(yend) * xgap);

		for (x = xpxl1 + 1; x < xpxl2; x++)
        {
			plot(param, rgb, x, IPART_(intery), RFPART_(intery));
			plot(param, rgb, x, IPART_(intery) + 1, FPART_(intery));
			intery += gradient;
		}
	}
	else
	{
		if (line.y1 < line.y0)
		{
			SWAP_(line.x0, line.x1);
			SWAP_(line.y0, line.y1);
		}
		gradient = dx / dy;
		yend = ROUND_(line.y0);
		xend = line.x0 + gradient*(yend - line.y0);
		ygap = RFPART_(line.y0 + 0.5);
		ypxl1 = yend;
		xpxl1 = IPART_(xend);
		plot(param, rgb, xpxl1, ypxl1, RFPART_(xend)*ygap);
		plot(param, rgb, xpxl1 + 1, ypxl1, FPART_(xend)*ygap);
		interx = xend + gradient;

		yend = ROUND_(line.y1);
		xend = line.x1 + gradient*(yend - line.y1);
		ygap = FPART_(line.y1 + 0.5);
		ypxl2 = yend;
		xpxl2 = IPART_(xend);
		plot(param, rgb, xpxl2, ypxl2, RFPART_(xend) * ygap);
		plot(param, rgb, xpxl2 + 1, ypxl2, FPART_(xend) * ygap);

		for (y = ypxl1 + 1; y < ypxl2; y++)
        {
			plot(param, rgb, IPART_(interx), y, RFPART_(interx));
			plot(param, rgb, IPART_(interx) + 1, y, FPART_(interx));
			interx += gradient;
		}
	}
}
