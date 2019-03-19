/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotation_matrix.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 17:22:46 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 17:35:18 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

t_matrix	rot_x(double rad)
{
	t_matrix mat;

	mat.x0 = 1;
	mat.y0 = 0;
	mat.z0 = 0;
	mat.x1 = 0;
	mat.y1 = cos(rad);
	mat.z1 = -sin(rad);
	mat.x2 = 0;
	mat.y2 = sin(rad);
	mat.z2 = cos(rad);
	return (mat);
}

t_matrix	rot_y(double rad)
{
	t_matrix mat;

	mat.x0 = cos(rad);
	mat.y0 = 0;
	mat.z0 = sin(rad);
	mat.x1 = 0;
	mat.y1 = 1;
	mat.z1 = 0;
	mat.x2 = -sin(rad);
	mat.y2 = 0;
	mat.z2 = cos(rad);
	return (mat);
}

t_matrix	rot_z(double rad)
{
	t_matrix mat;

	mat.x0 = cos(rad);
	mat.y0 = -sin(rad);
	mat.z0 = 0;
	mat.x1 = sin(rad);
	mat.y1 = cos(rad);
	mat.z1 = 0;
	mat.x2 = 0;
	mat.y2 = 0;
	mat.z2 = 1;
	return (mat);
}

t_matrix	rot_matrix(char axe, t_param *param)
{
	if (axe == 'x')
		return (rot_x(param->angx * (M_PI / 180)));
	else if (axe == 'y')
		return (rot_y(param->angy * (M_PI / 180)));
	else
		return (rot_z(param->angz * (M_PI / 180)));
}
