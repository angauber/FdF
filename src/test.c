/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:48:58 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 16:31:34 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	changeBrightness(t_rgb *rgb, float c)
{
	rgb->r = c * (float)rgb->r;
	rgb->g = c * (float)rgb->g;
	rgb->b = c * (float)rgb->b;
}

int		rgbToInt(t_rgb rgb) {
	return (65536 * rgb.r + 256 * rgb.g + rgb.b);
}

void	intToRgb(t_rgb *rgb, int nb) {
	rgb->r = nb / 65536;
	rgb->g = (nb / 256) % 256;;
	rgb->b = nb % 256;
}

void	plot(t_mlx mlx, t_rgb rgb, int x, int y, float c) {
	changeBrightness(&rgb, c);
	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, rgbToInt(rgb));
}

void	draw_line_antialias(t_mlx mlx, t_line line, t_rgb rgb)
{
	double	dx = (double)line.x1 - (double)line.x0;
	double	dy = (double)line.y1 - (double)line.y0;
	double	size = hypot(dx, dy);

	if (fabs(dx) > fabs(dy)) {
		if (line.x1 < line.x0){
			swap_(line.x0, line.x1);
			swap_(line.y0, line.y1);
		}
		double gradient = dy / dx;
		double xend = round_(line.x0);
		double yend = line.y0 + gradient*(xend - line.x0);
		double xgap = rfpart_(line.x0 + 0.5);
		int xpxl1 = xend;
		int ypxl1 = ipart_(yend);
		plot(mlx, rgb, xpxl1, ypxl1, rfpart_(yend) * xgap);
		plot(mlx, rgb, xpxl1, ypxl1 + 1, fpart_(yend) * xgap);
		double intery = yend + gradient;

		xend = round_(line.x1);
		yend = line.y1 + gradient*(xend - line.x1);
		xgap = fpart_(line.x1 + 0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		plot(mlx, rgb, xpxl2, ypxl2, rfpart_(yend) * xgap);
		plot(mlx, rgb, xpxl2, ypxl2 + 1, fpart_(yend) * xgap);

		int x;
		for(x = xpxl1 + 1; x < xpxl2; x++) {
			plot(mlx, rgb, x, ipart_(intery), rfpart_(intery));
			plot(mlx, rgb, x, ipart_(intery) + 1, fpart_(intery));
			intery += gradient;
		}
	}
	else
	{
		if (line.y1 < line.y0)
		{
			swap_(line.x0, line.x1);
			swap_(line.y0, line.y1);
		}
		double gradient = dx / dy;
		double yend = round_(line.y0);
		double xend = line.x0 + gradient*(yend - line.y0);
		double ygap = rfpart_(line.y0 + 0.5);
		int ypxl1 = yend;
		int xpxl1 = ipart_(xend);
		plot(mlx, rgb, xpxl1, ypxl1, rfpart_(xend)*ygap);
		plot(mlx, rgb, xpxl1 + 1, ypxl1, fpart_(xend)*ygap);
		double interx = xend + gradient;

		yend = round_(line.y1);
		xend = line.x1 + gradient*(yend - line.y1);
		ygap = fpart_(line.y1 + 0.5);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);
		plot(mlx, rgb, xpxl2, ypxl2, rfpart_(xend) * ygap);
		plot(mlx, rgb, xpxl2 + 1, ypxl2, fpart_(xend) * ygap);

		int y;
		for(y = ypxl1 + 1; y < ypxl2; y++) {
			plot(mlx, rgb, ipart_(interx), y, rfpart_(interx));
			plot(mlx, rgb, ipart_(interx) + 1, y, fpart_(interx));
			interx += gradient;
		}
	}
}

/*
int		main() {
	t_mlx		mlx;
	t_line		line;
	t_rgb		rgb1;
	t_rgb		rgb2;

	line.x0 = 800;
	line.y0 = 100;

	line.x1 = 850;
	line.y1 = 600;

	intToRgb(&rgb1, 0xFFFFFF);
	intToRgb(&rgb2, 0x2D7EFF);
    
	mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1600, 900, "FdF");

	//mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, x, y, rgbToInt(rgb));
   	draw_line_antialias(mlx, line, rgb1);
    mlx_loop(mlx.mlx_ptr);
    return (0);
}
*/