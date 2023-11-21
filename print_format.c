/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:37:16 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/21 11:27:08 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_ptr(unsigned long ptr)
{
	int	c;

	c = 0;
	c = h(c, ft_putstr_fd("0x", 1));
	if (c == -1)
		return (-1);
	c = h(c, print_hex((unsigned long)ptr, 'x'));
	if (c == -1)
		return (-1);
	return (c);
}

int	pr_format(char spec, va_list lst_args)
{
	int	c;

	c = 0;
	if (spec == 'c')
		c = h(c, ft_putchar_fd(va_arg(lst_args, int), 1));
	else if (spec == 's')
		c = h(c, ft_putstr_fd(va_arg(lst_args, char *), 1));
	else if (spec == 'd' || spec == 'i')
		c = h(c, ft_putnbr_fd(va_arg(lst_args, int), 1));
	else if (spec == 'u')
		c = h(c, print_u(va_arg(lst_args, unsigned long)));
	else if (spec == 'x' || spec == 'X')
		c = h(c, print_hex(va_arg(lst_args, unsigned int), spec));
	else if (spec == 'p')
		c = h(c, print_ptr(va_arg(lst_args, unsigned long)));
	else if (spec == '%')
		c = h(c, ft_putchar_fd(spec, 1));
	if (c == -1)
		return (-1);
	return (c);
}
