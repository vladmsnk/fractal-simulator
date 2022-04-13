#include "../includes/fractol.h"

int cross_close(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	//mlx_destroy_image(data->mlx_ptr, &data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
}

int check_name(char *name)
{
	if (!ft_strncmp("Julia", name, 5) || !ft_strncmp("Mandelbrot", name, 10)
		|| !ft_strncmp("Burning", name, 7))
		return (1);
	return (0);
}

t_cmplx	complex(float re, float im)
{
	t_cmplx	z;

	z.re = re;
	z.im = im;
	return (z);
}

t_cmplx scale(t_cmplx num, t_plane plane)
{
	return complex(num.re / WIDTH * (plane.re_max - plane.re_min)  + plane.re_min, 
			num.im / HEIGHT * (plane.im_max - plane.im_min)  + plane.im_min);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}