/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:37:16 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/16 18:00:06 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdint.h>

int	print_str(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += ft_putstr_fd("(null)", 1);
	else
		count += ft_putstr_fd((char *)n, 1);
	return (count);
}

int	print_ptr(long long n)
{
	char		*s;
	int			count;

	s = "0x0";
	count = 0;
	if (n == 0)
	{
		count += ft_putstr_fd(s, 1);
		return (count);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	ft_putstr_fd("0x", 1);
	count += print_digit(n, 16, 'p');
	return (count + 2);
}

int	print_digit_u(unsigned int n)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 10)
		return (ft_putchar_fd(symbols[n], 1));
	else
	{
		count = print_digit_u(n / 10);
		return (count + print_digit_u(n % 10));
	}
}

int	print_digit(long long n, int base, char spec)
{
	int		count;
	char	*symbols;
	char	*symbols_u;

	count = 0;
	symbols = "0123456789abcdef";
	symbols_u = "0123456789ABCDEF";
	if (n < 0 && base != 16)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, spec) + 1);
	}
	else if (n < base)
	{
		if (spec == 'X')
			return (ft_putchar_fd(symbols_u[n], 1));
		else
			return (ft_putchar_fd(symbols[n], 1));
	}
	else
	{
		count = print_digit(n / base, base, spec);
		return (count + print_digit(n % base, base, spec));
	}
}

int	print_format(char spec, va_list lst_args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar_fd(va_arg(lst_args, int), 1);
	else if (spec == 's')
		count += print_str(va_arg(lst_args, long int));
	else if (spec == 'd' || spec == 'i')
		count += print_digit(va_arg(lst_args, int), 10, spec);
	else if (spec == 'u')
		count += print_digit_u(va_arg(lst_args, unsigned long));
	else if (spec == 'x' || spec == 'X')
		count += print_digit(va_arg(lst_args, unsigned int), 16, spec);
	else if (spec == 'p')
		count += print_ptr(va_arg(lst_args, unsigned long));
	else if (spec == '%')
		count += ft_putchar_fd(spec, 1);
	return (count);
}
