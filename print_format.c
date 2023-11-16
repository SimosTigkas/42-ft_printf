/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:37:16 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/16 12:08:53 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(long int n, char spec)
{
	long int	*ptr;
	char		*s;
	int			i;
	long int	a;

	s = "(null)";
	i = 0;
	ptr = &n;
	if (ptr == NULL)
	{
		while (s)
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
		return (i);
	}
	a = *ptr;
	ft_putstr_fd("0x", 1);
	return (print_digit(a, 16, spec) + 2);
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

int	print_digit(long int n, int base, char spec)
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
		count += print_ptr(va_arg(lst_args, long), spec);
	else
		count += ft_putchar_fd(spec, 1);
	return (count);
}
