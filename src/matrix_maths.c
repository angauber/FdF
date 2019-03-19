/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix_maths.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 17:36:23 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 17:44:11 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fdf.h"

void		rotate_matrix(t_param *param)
{
	t_matrix yz;

	yz = matrix_calcul(rot_matrix('y', param), rot_matrix('z', param));
	param->matrix = matrix_calcul(rot_matrix('x', param), yz);
}

t_matrix	matrix_calcul(t_matrix rot, t_matrix main)
{
	t_matrix new;

	new.x0 = (main.x0 * rot.x0) + (main.y0 * rot.x1) + (main.z0 * rot.x2);
	new.y0 = (main.x0 * rot.y0) + (main.y0 * rot.y1) + (main.z0 * rot.y2);
	new.z0 = (main.x0 * rot.z0) + (main.y0 * rot.z1) + (main.z0 * rot.z2);
	new.x1 = (main.x1 * rot.x0) + (main.y1 * rot.x1) + (main.z1 * rot.x2);
	new.y1 = (main.x1 * rot.y0) + (main.y1 * rot.y1) + (main.z1 * rot.y2);
	new.z1 = (main.x1 * rot.z0) + (main.y1 * rot.z1) + (main.z1 * rot.z2);
	new.x2 = (main.x2 * rot.x0) + (main.y2 * rot.x1) + (main.z2 * rot.x2);
	new.y2 = (main.x2 * rot.y0) + (main.y2 * rot.y1) + (main.z2 * rot.y2);
	new.z2 = (main.x2 * rot.z0) + (main.y2 * rot.z1) + (main.z2 * rot.z2);
	return (new);
}

void		mult_matrix(t_matrix mat, t_dot *dot1, t_dot *dot2)
{
	t_dot new1;
	t_dot new2;

	new1.x = (dot1->x * mat.x0) + (dot1->y * mat.y0) + (dot1->z * mat.z0);
	new1.y = (dot1->x * mat.x1) + (dot1->y * mat.y1) + (dot1->z * mat.z1);
	new1.z = (dot1->x * mat.x2) + (dot1->y * mat.y2) + (dot1->z * mat.z2);
	new2.x = (dot2->x * mat.x0) + (dot2->y * mat.y0) + (dot2->z * mat.z0);
	new2.y = (dot2->x * mat.x1) + (dot2->y * mat.y1) + (dot2->z * mat.z1);
	new2.z = (dot2->x * mat.x2) + (dot2->y * mat.y2) + (dot2->z * mat.z2);
	dot1->x = new1.x;
	dot1->y = new1.y;
	dot1->z = new1.z;
	dot2->x = new2.x;
	dot2->y = new2.y;
	dot2->z = new2.z;
}
