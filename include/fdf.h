/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: angauber <angauber@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:49:02 by angauber     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 18:19:15 by angauber    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include "../ft_printf/include/ft_printf.h"
#include "../minilibx_macos/mlx.h"

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X))+0.5))
#define fpart_(X) (((double)(X))-(double)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))
 
#define swap_(a, b) do{ __typeof__(a) tmp;  tmp = a; a = b; b = tmp; }while(0)

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

typedef	struct		s_vector
{
	double			ix;
	double			iy;
	double			jx;
	double			jy;
	double			kx;
	double			ky;
}					t_vector;

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
}					t_dot;

typedef struct		s_line
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_line;

typedef struct		s_ortho
{
	double			A1;
	double			A2;
	double			B1;
	double			B2;
	int				x;
	int				y;
}					t_ortho;

typedef struct		s_map
{
	int				**table;
	int				x;
	int				y;
}					t_map;

void				render_map(t_map *map);
void				draw_line_antialias(t_mlx mlx, t_line line, t_rgb rgb);