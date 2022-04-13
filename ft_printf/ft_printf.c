/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:27 by jjhezane          #+#    #+#             */
/*   Updated: 2021/12/11 16:18:46 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t	iter;
	char	*to_out;

	iter = 0;
	while (*(s + iter) != '\0' && *(s + iter) != (char)c)
		iter++;
	if (*(s + iter) == (char)c)
	{
		to_out = (char *)(s + iter);
		return (to_out);
	}
	return (NULL);
}

static char	*init_conditions(void)
{
	char	*convs;

	convs = (char *)malloc(sizeof(char) * 10);
	if (!convs)
		return (NULL);
	convs[0] = 'c';
	convs[1] = 's';
	convs[2] = 'p';
	convs[3] = 'd';
	convs[4] = 'i';
	convs[5] = 'u';
	convs[6] = 'x';
	convs[7] = 'X';
	convs[8] = '%';
	convs[9] = '%';
	return (convs);
}

static int	print_by_specifier(char c, va_list ap)
{
	int	printed;

	printed = 0;
	if (c == 'd' || c == 'i')
		printed = ft_print_integer(va_arg(ap, int));
	else if (c == 'c')
		printed = ft_print_char(va_arg(ap, int));
	else if (c == 's')
		printed = ft_print_str(va_arg(ap, char *));
	else if (c == 'x')
		printed = ft_print_hex(va_arg(ap, unsigned), &print_arr_reverse_low);
	else if (c == 'X')
		printed = ft_print_hex(va_arg(ap, unsigned), &print_arr_reverse_upper);
	else if (c == 'p')
		printed = ft_print_ptr(va_arg(ap, void *));
	else if (c == 'u')
		printed = ft_print_unsigned(va_arg(ap, unsigned));
	else if (c == '%')
		printed = ft_print_char('%');
	return (printed);
}

static int	prnt_all_as_format_tells(const char *format, va_list ap)
{
	t_flags	flags;
	int		tmp;
	int		printed;

	flags.simple = init_conditions();
	tmp = 0;
	printed = 0;
	while (*format)
	{
		if (*format == '%' && !tmp)
			tmp = 1;
		else if (tmp && ft_strchr(flags.simple, *format))
		{
			printed += print_by_specifier(*format, ap);
			tmp = 0;
		}
		else if (!tmp)
			printed += ft_print_char(*format);
		else
			return (-1);
		format++;
	}
	free(flags.simple);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		printed_count;
	va_list	ap;

	va_start(ap, format);
	printed_count = prnt_all_as_format_tells(format, ap);
	va_end(ap);
	return (printed_count);
}
