#include <stdio.h>
#include "libft.h"
#include "../../include/fractol.h"
/*
 **
 **		◦ open, read, write, close
		◦ malloc, free
		◦ perror, strerror
		◦ exit
		◦ All the functions defined in the math library (-lm and man 3 math)
		◦ All the functions defined in the miniLibX library.
 */

int					fdf_put_pixel_to_image(t_frc *gnrl, int x, int y, int color)
{
	unsigned int	*dst;

	if (x > gnrl->width_i || y > gnrl->width_i || x < 0 || y < 0)
	{
		return (0);
	}
	dst = (unsigned int *)gnrl->addr;
	dst[x + (y * gnrl->size_l / 4)] = color;
	return (0);
}

int			get_color(int i, int j)
{
	int		color_r;
	int		color_g;
	int		color_b;

	color_r = (i + 3j)/5;
	color_g = (i + j)/5;
	color_b = (i + 13j)/2;
	return ((color_r << 16) & 0xff0000  | (color_g << 8) & 0x00ff00 | color_b & 0x0000ff);
}

void		paint_unit(t_frc *gnrl)
{
	static int	created;
	int			color;

	if (created == 0)
		created = 1;
	else
	{
		mlx_destroy_image(gnrl->mlx, gnrl->img);
		mlx_clear_window(gnrl->mlx, gnrl->window);
	}
//	init_image(fdf, fdf->image.w, fdf->image.h);
	gnrl->img = mlx_new_image(gnrl->mlx, gnrl->width_i, gnrl->height_i);
	gnrl->addr = mlx_get_data_addr(gnrl->img, &gnrl->bit_pp, &gnrl->size_l, &gnrl->endian);

//	render 1 pixel
	for (int i = 0; i < 1000; ++i) {
		for(int j = 0; j < 1000;  ++j){
			color = get_color(i, j);
			fdf_put_pixel_to_image(gnrl, i, j, color);
		}

	}

	mlx_put_image_to_window(gnrl->mlx, gnrl->window, gnrl->img, 1, 1);


	//mlx_hook() //TODO: создать менеджер хуков для окна
	mlx_loop(gnrl->mlx);
//	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image.img, 0, 0);
//	render_menu(fdf);
}

void		init_display(t_frc *gnrl, char *name)
{
	gnrl->width_w = WIN_W;
	gnrl->height_w = WIN_H;
	gnrl->width_i = gnrl->width_w;
	gnrl->height_i = gnrl->width_i; //?
	gnrl->mlx = mlx_init();
	gnrl->window = mlx_new_window(gnrl->mlx, gnrl->width_w, gnrl->height_w, name);
}

int			core(int ac, char **av)						//TODO: добавить инициализацию нескольких окон для нескольких аргументов
{ 														//TODO: добавить проверку на название аргумента
	t_frc	general;

	init_display(&general, "FRACTOL");
	paint_unit(&general);
	return (0);
}

void		usage(void)
{
	ft_printf("Wrong params\n");
	exit(1);
}

int			main(int ac, char **av) {
	if (ac == 1)
		usage();
	else
		core(ac, av);
	return 0;
}
