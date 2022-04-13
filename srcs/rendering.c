#include "../includes/fractol.h"

int escape(t_cmplx z, t_cmplx c, int flag)
{
	int		cnt;
	float	tmp_z_re;

	cnt = 0;
	while ((z.re * z.re + z.im * z.im < 4) && (cnt < MAX_ITER))
	{
		tmp_z_re = z.re * z.re - z.im * z.im + c.re;
		if (!flag)
			z.im = 2 * z.re * z.im + c.im;
		else 
			z.im = fabsf(2 * z.re * z.im) + c.im;
		z.re = tmp_z_re;
		cnt++;
	}
	return (cnt);
}

int julia_wrapper(int x, int y, t_data *data)
{
	t_cmplx	z;

	z = scale(complex(x, y), data->plane);
	return (escape(z, data->jul_inf.c, 0));
}

int mandelbrot_wrapper(int x, int y, t_data *data)
{
	t_cmplx	c;

	c = scale(complex(x, y), data->plane);
	return (escape(complex(0,0), c, 0));
}

int burning_wrapper(int x, int y, t_data *data)
{
	t_cmplx	c;

	c = scale(complex(x, y), data->plane);
	return (escape(complex(0,0), c, 1));
}

int draw(t_data *data, int (*f)(int, int, t_data *))
{
	int 	cnt;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cnt = f(x, y, data);
			img_pix_put(&(data->img), x, y, create_trgb(0, cnt % 8 * (16 + 2 * data->c_shifter),
				 cnt % 4 * (32 + data->c_shifter), cnt % 2 * (128 + data->c_shifter / 2)));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void	draw_fractal(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (!ft_strncmp("Mandelbrot", data->name, 10))
		draw(data, &mandelbrot_wrapper);
	else if (!ft_strncmp("Julia", data->name, 5))
		draw(data, &julia_wrapper);
	else
		draw(data, &burning_wrapper);
}