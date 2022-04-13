/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:29 by jjhezane          #+#    #+#             */
/*   Updated: 2021/12/11 16:18:17 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct flags
{
	char	*simple;
}	t_flags;

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_integer(int n);
int	ft_print_hex(unsigned long n, int (*print_hex)(unsigned long *, int));
int	print_arr_reverse_low(unsigned long *s, int i);
int	print_arr_reverse_upper(unsigned long *s, int i);
int	ft_print_ptr(void *p);
int	ft_print_unsigned(unsigned long n);
#endif