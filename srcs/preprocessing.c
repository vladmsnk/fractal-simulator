#include "../includes/fractol.h"

void	init_params(t_data *data)
{
	data->plane.re_min = -2.2;
	data->plane.re_max = 1.2;
	data->plane.im_min = -1.7;
	data->plane.im_max = 1.7;
	data->c_shifter = 0;
	data->multiple = 1;
	data->max_iter = 100;
}

void	upload_props(int argc, char **argv, t_data *data)
{
	if (!ft_strncmp("Julia", argv[1], 5))
	{
		if (argc == 4)
		{
			(data->jul_inf).c.re = ft_str2float(argv[2]);
			(data->jul_inf).c.im = ft_str2float(argv[3]);
		}
	}
}

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, data->name);
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return (0);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &(data->img.bpp),
			&(data->img.line_len), &(data->img.endian));
	return (1);
}


int parcing(int argc, char **argv, t_data *data)
{
	if (argc > 1)
	{
		data->name = argv[1];
		if (check_name(data->name))
		{
			upload_props(argc, argv, data);
			return (1);
		} 
	} 
	print_helper();
	exit(EXIT_FAILURE);
}

int preprocessing(int argc, char **argv, t_data *data)
{
	if (parcing(argc, argv, data))
	{
		init_params(data);
		return (init_window(data));
	}
	return (0);
}