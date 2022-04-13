#include "../includes/fractol.h"

static int check_valid(const char *str)
{
	int	i;
	int	dot_cnt;
	int is_neg;

	i = 0;
	is_neg = 0;
	dot_cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && i == 0)
			is_neg = 1;
		else if ((str[i] > '9' || str[i] < '0') && str[i] != '.')
			return (0);
		else if ((str[i] == '.' && dot_cnt >= 1) || (str[i] == '-' && is_neg > 0))
			return (0);
		i++;
	}
	return (1);
}

float ft_str2float(const char *str)
{
	int 	whole;
	int		frac;
	int		dot_i;
	float	num;
	int		dec;

	num = 0.0;
	dec = 1;
	if (check_valid(str))
	{
		dot_i = 0;
		whole = ft_atoi(str);
		while (str[dot_i] != '.')
			dot_i++;
		frac = ft_atoi(str + dot_i + 1);
		num += whole;
		while (frac / dec > 0)
			dec *= 10;
		if (num < 0)
			num = num +  -1 * (float)frac / (float)dec;
		else
			num = num + (float)frac / (float)dec;
		return (num);
	}
	return (-100);
}