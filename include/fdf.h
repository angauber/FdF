/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:49:02 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 18:10:12 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define IPART_(X) ((int)(X))
# define ROUND_(X) ((int)(((double)(X))+0.5))
# define FPART_(X) (((double)(X))-(double)IPART_(X))
# define RFPART_(X) (1.0-FPART_(X))
# define SWAP_(a, b) do{ __typeof__(a) tmp;  tmp = a; a = b; b = tmp; }while(0)

# include <fcntl.h>
# include <math.h>
# include "../ft_printf/include/ft_printf.h"
# include "../minilibx_macos/mlx.h"

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef	struct		s_2d_dot
{
	int 			x;
	int				y;
}					t_2d_dot;

typedef	struct		s_matrix
{
	double			x0;
	double			y0;
	double			z0;
	double			x1;
	double			y1;
	double			z1;
	double			x2;
	double			y2;
	double			z2;
}					t_matrix;

typedef struct		s_dot
{
	double			x;
	double			y;
	double			z;
}					t_dot;

typedef struct		s_line
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_line;

typedef struct		s_map
{
	int				**table;
	int				zmax;
	int				zmin;
	int				x;
	int				y;
}					t_map;

typedef struct		s_param
{
	double			angx;
	double			angy;
	double			angz;
	double			scale;
	double			factor;
	int				proj;
	int				x;
	int				y;
	int				hue;
	void			*img;
	int				*addr;
	t_mlx			mlx;
	t_matrix		matrix;
	t_rgb 			rgb;
	t_map			*map;
}					t_param;

typedef struct		s_xiaolin
{
	double			dx; 
	double			dy;
	double			gradient;
	double			xend;
	double			yend;
	double			xgap;
	double			ygap;
	double			inter;
	int				xpxl1;
	int				ypxl1;
	int				xpxl2;
	int				ypxl2;
}					t_xiaolin;

typedef struct		s_hsv
{
	double			f;
	double			p;
	double			q;
	double			t;
}					t_hsv;

void				render_map(t_map *map);
void				draw_line_antialias(t_param *param, t_line line, t_rgb rgb);
void				change_brightness(t_rgb *rgb, float c);
int					rgb_to_int(t_rgb *margb);
void				int_to_rgb(t_rgb *rgb, int nb);
void				plot(t_param *param, int x, int y, float c);
t_rgb 				create_from_hsv(double h, double s, double v);
t_rgb				create_color(int current, t_2d_dot polar, int start, int range);
t_matrix			rot_matrix(char axe, t_param *param);
void				rotate_matrix(t_param *param);
void				mult_matrix(t_matrix mat, t_dot *dot1, t_dot *dot2);
t_matrix			matrix_calcul(t_matrix rot, t_matrix main);
void				render_all_points(t_param *param);
int					key_press(int key, t_param *param);
void				calculate_line(t_param *param, t_dot dot1, t_dot dot2);

#endif
