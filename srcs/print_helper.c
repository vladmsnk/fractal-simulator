#include "../includes/fractol.h"


void	print_helper()
{
	ft_printf("%s\n", "For Mandelbrot, Burning run ./fractol {name}");
	ft_printf("%s\n", "For Julia run ./fractol Julia {c.re} {c.im}");
	ft_printf("%s\n", "To change color click C");
	ft_printf("%s\n", "To change a color shift mode click 1,2,3");
	ft_printf("%s\n", "To zoom use a mouse wheel");
	ft_printf("%s\n", "To move along the screen use key arrows");
}