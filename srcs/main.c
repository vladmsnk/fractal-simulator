#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (preprocessing(argc, argv, &data))
	{
		draw_fractal(&data);
		handle_hooks(data);
	}
	return (0);
}