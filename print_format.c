/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:37:16 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/17 14:13:44 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdint.h>

int	print_ptr(unsigned long n)
{
	int	count;

	count = 0;
	ft_putstr_fd("0x", 1);
	count += print_hex(n, 'x');
	return (count + 2);
}

int	print_format(char spec, va_list lst_args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar_fd(va_arg(lst_args, int), 1);
	else if (spec == 's')
		count += ft_putstr_fd((char *)va_arg(lst_args, long int), 1);
	else if (spec == 'd' || spec == 'i')
		count += print_dec(va_arg(lst_args, int));
	else if (spec == 'u')
		count += print_u(va_arg(lst_args, unsigned long));
	else if (spec == 'x' || spec == 'X')
		count += print_hex(va_arg(lst_args, unsigned int), spec);
	else if (spec == 'p')
		count += print_ptr(va_arg(lst_args, unsigned long));
	else if (spec == '%')
		count += ft_putchar_fd(spec, 1);
	else
		count += ft_putchar_fd(spec, 1);
	return (count);
}
