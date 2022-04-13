/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:20 by jjhezane          #+#    #+#             */
/*   Updated: 2021/12/11 16:19:25 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arr_reverse_upper(unsigned long *s, int i)
{
	int	printed;

	printed = 0;
	while (i != -1)
	{
		if (s[i] >= 10)
			printed += ft_print_char(s[i] + 55);
		else
			printed += ft_print_char(s[i] + 48);
		i--;
	}
	return (printed);
}

int	print_arr_reverse_low(unsigned long *s, int i)
{
	int	printed;

	printed = 0;
	while (i != -1)
	{
		if (s[i] >= 10)
			printed += ft_print_char(s[i] + 87);
		else
			printed += ft_print_char(s[i] + 48);
		i--;
	}
	return (printed);
}

int	ft_print_hex(unsigned long n, int (*print_hex)(unsigned long *, int))
{
	unsigned long	rmndrs[30];
	unsigned long	rem;
	int				i;

	rem = 0;
	i = 0;
	if (n == 0)
		return (ft_print_char('0'));
	while (n != 0)
	{
		rem = n % 16;
		n /= 16;
		rmndrs[i++] = rem;
	}
	i--;
	return (print_hex(rmndrs, i));
}
