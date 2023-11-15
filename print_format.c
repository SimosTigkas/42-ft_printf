/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:37:16 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/15 17:15:41 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long int ptr)
{
	int		count;
	char	*symbols;
	char	buffer[20];
	int		i;

	i = 0;
	count = ft_putstr_fd("0x", 1);
	symbols = "012345678abcdef";

	if (ptr == 0)
		count += ft_putchar_fd('0', 1);
	else
	{
		while (ptr)
		{
			buffer[i++] = symbols[ptr % 16];
			ptr /= 16;
		}
		i--;
		while (i >= 1)
		{
			count += ft_putchar_fd(buffer[--i], 1);
		}
	}
	return (count);
}

int	print_digit_u(unsigned int n)
{
	int		count;
	char	*symbols;
	char	*symbols_u;

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

int	print_digit(long n, int base, char spec)
{
	int		count;
	char	*symbols;
	char	*symbols_u;

	count = 0;
	symbols = "0123456789abcdef";
	symbols_u = "0123456789ABCDEF";

	if (n < 0)
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
		count += ft_putstr_fd(va_arg(lst_args, char *), 1);
	else if (spec == 'd' || spec == 'i')
		count += print_digit((long)va_arg(lst_args, int), 10, spec);
	else if (spec == 'u')
		count += print_digit_u((unsigned int)va_arg(lst_args, int));
	else if (spec == 'x' || spec == 'X')
		count += print_digit((long)va_arg(lst_args, unsigned int), 16, spec);
	else if (spec == 'p')
		count += print_ptr(va_arg(lst_args, unsigned long int));
	else
		count += ft_putchar_fd(spec, 1);
	return (count);
}
