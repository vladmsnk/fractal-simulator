#include "../includes/fractol.h"

void handle_color(int keysym, t_data *data)
{
	if (keysym == 8) 
	{
		data->c_shifter = ++data->c_shifter * data->multiple;
		draw_fractal(data);
	}
	else if (keysym == 9) {
		data->c_shifter = 0;
		data->multiple = 1;
		draw_fractal(data);
	}
	data->c_shifter /= data->multiple;
	if (keysym == 18)
		data->multiple = 1;
	else if (keysym == 19)
		data->multiple = 2;
	else if (keysym == 20)
		data->multiple = 3;
	data->c_shifter *= data->multiple;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (keysym >= 123 && keysym <= 126)
	{
		move_picture(keysym, data);
		draw_fractal(data);
	}
	handle_color(keysym, data);
	return (0);
}

int	move_picture(int keysym, t_data *data)
{
	float		dx;
	float		dy;

	dx = (data->plane.re_max - data->plane.re_min) * MOVE;
	dy = (data->plane.im_max - data->plane.im_min) * MOVE;
	if (keysym == 123 || keysym == 124)
	{
		data->plane.re_min = (keysym == 123) * (data->plane.re_min - dx) +  (keysym == 124) * (data->plane.re_min + dx);
		data->plane.re_max = (keysym == 123) * (data->plane.re_max - dx) +  (keysym == 124) * (data->plane.re_max + dx);
	}
	else if (keysym == 125 || keysym == 126)
	{
		data->plane.im_min = (keysym == 126) * (data->plane.im_min - dx) +  (keysym == 125) * (data->plane.im_min + dx);
		data->plane.im_max = (keysym == 126) * (data->plane.im_max - dx) +  (keysym == 125) * (data->plane.im_max + dx);
	}
	return (0);
}

int zoom_picture(int keysym,int x, int y, t_data *data)
{
	float zoom;
	float cr;
	float ci;
	float tmpr;
	float tmpi;

	if (keysym == 4 || keysym == 5)
	{
		if (keysym == 5) 
			zoom = 2.5;
		else
			zoom = 1.5;
		cr = data->plane.re_min + (data->plane.re_max - data->plane.re_min) * x / WIDTH;
		ci = data->plane.im_min + (data->plane.im_max - data->plane.im_min) * y / HEIGHT;
		tmpr = cr - (data->plane.re_max - data->plane.re_min) / zoom;
		data->plane.re_max = cr + (data->plane.re_max - data->plane.re_min) / zoom;
		data->plane.re_min = tmpr;
		tmpi = ci - (data->plane.im_max - data->plane.im_min) / zoom;
		data->plane.im_max = ci + (data->plane.im_max - data->plane.im_min) / zoom;
		data->plane.im_min = tmpi;
		draw_fractal(data);
	}
	return (0);
}

void handle_hooks(t_data data)
{
	mlx_hook(data.win_ptr, 02, (1L<<0), &handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, cross_close, &data);
	mlx_mouse_hook(data.win_ptr, &zoom_picture, &data);
	mlx_loop(data.mlx_ptr);
}
