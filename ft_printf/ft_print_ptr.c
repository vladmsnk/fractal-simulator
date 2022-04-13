/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhezane <jjhezane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:25 by jjhezane          #+#    #+#             */
/*   Updated: 2021/12/11 16:18:54 by jjhezane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *p)
{
	int			printed;
	uintptr_t	p1;

	printed = 0;
	p1 = (uintptr_t)p;
	printed += ft_print_char('0');
	printed += ft_print_char('x');
	printed += ft_print_hex(p1, &print_arr_reverse_low);
	return (printed);
}
