/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:22 by jjhezane          #+#    #+#             */
/*   Updated: 2021/12/11 16:19:01 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	count_digts(long n)
{
	unsigned int	cnt;

	if (n < 0)
		n *= -1;
	cnt = 0;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static unsigned int	get_tens(long n)
{
	unsigned int	t;
	unsigned int	i;

	i = 0;
	t = 1;
	while ((int)i < n)
	{
		t *= 10;
		i++;
	}
	return (t);
}

static void	parse_int(long n, unsigned int *digit_amount, char *str)
{
	unsigned int	iter;

	if (n < 0)
	{
		str[0] = '-';
		iter = 1;
		(*digit_amount)++;
		n *= -1;
	}
	else
		iter = 0;
	while (iter < *digit_amount)
	{
		str[iter] = (n / (get_tens(*digit_amount - iter - 1))) % 10 + 48;
		iter++;
	}
	str[iter] = '\0';
}

int	ft_print_integer(int n)
{
	unsigned int	digit_amount;
	char			*str;

	if (n == 0)
		return (ft_print_char('0'));
	digit_amount = count_digts(n);
	if (n < 0)
	{
		str = (char *)malloc((digit_amount + 2) * sizeof(char));
		if (!str)
			return (0);
	}
	else
	{
		str = (char *)malloc((digit_amount + 1) * sizeof(char));
		if (!str)
			return (0);
	}
	parse_int(n, &digit_amount, str);
	write(1, str, digit_amount);
	free(str);
	return (digit_amount);
}

int	ft_print_unsigned(unsigned long n)
{
	unsigned int	digit_amount;
	char			*str;

	if (n == 0)
		return (ft_print_char('0'));
	digit_amount = count_digts(n);
	str = (char *)malloc((digit_amount + 1) * sizeof(char));
	if (!str)
		return (-1);
	parse_int(n, &digit_amount, str);
	write(1, str, digit_amount);
	free(str);
	return (digit_amount);
}
