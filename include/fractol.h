#ifndef FRACT_FRACTOL_H
# define FRACT_FRACTOL_H

# include "ft_printf.h"
# include <mlx.h>
# include <math.h>
# define WIN_W 1000
# define WIN_H 1000

typedef struct			s_cx
{
	double				i;
	double				r;
}						t_cx;


typedef struct		s_frc
{
	void			*mlx;			//mlx
	void			*window;		//win
	void			*img;			//img
	char			*addr;			// addr of img for mlx
	int				bit_pp;			//bit per pixel for mlx
	int				size_l;			//size_line for mlx
	int				endian;			//endian for mlx

	int				width_w;
	int				height_w;
	int				width_i;
	int				height_i;

	int				margin_x;
	int				margin_y;

	t_cx			c_dig;			//complex_number
	}					t_frc;


#endif
