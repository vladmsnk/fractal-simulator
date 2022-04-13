#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 860
# define HEIGHT 860
# define MAX_ITER 200
# define MOVE 0.1

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "../ft_printf/ft_printf.h"

typedef	struct s_cmplx
{
	float re;
	float im;
}	t_cmplx;

typedef struct s_plane
{
	float re_min;
	float re_max;
	float im_min;
	float im_max;
}	t_plane;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef	struct s_jul_inf
{
	t_cmplx	c;
	int		color_num;
}	t_jul_inf;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_cmplx		cmplx;
	t_jul_inf 	jul_inf;
	t_plane 	plane;
	int 		max_iter;
	char 		*name;
	int			c_shifter;
	int			multiple;
}	t_data;

int		handle_keypress(int keysym, t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	img_pix_put(t_img *img, int x, int y, int color);
// int		start_mandelbrot(t_data *data);
// int 	start_julia(t_data *data);
int 	cross_close(t_data *data);
int		ft_atoi(const char *str);
void 	print_helper();
int 	check_name(char *name);
float 	ft_str2float(const char *str);
int 	*get_color_rgb(int color_num);
// void	init_plane(t_data *data);
int		move_picture(int keysym, t_data *data);
void	draw_fractal(t_data *data);
int 	handle_mouse(int keysym, t_data *data);
int 	zoom_picture(int keysym,int x, int y, t_data *data);
t_cmplx	complex(float re, float im);
t_cmplx scale(t_cmplx num, t_plane plane);
int		create_trgb(int t, int r, int g, int b);
int 	preprocessing(int argc, char **argv, t_data *data);
void 	handle_hooks(t_data data);
#endif