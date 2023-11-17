/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:27:56 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/17 09:00:57 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_u(unsigned int n)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 10)
		return (ft_putchar_fd(symbols[n], 1));
	else
	{
		count = print_u(n / 10);
		return (count + print_u(n % 10));
	}
}

int	print_hex(unsigned long n, char spec)
{
	int		count;
	char	*symbols;
	char	*symbols_u;

	count = 0;
	symbols = "0123456789abcdef";
	symbols_u = "0123456789ABCDEF";
	if (n < 16)
	{
		if (spec == 'X')
			return (ft_putchar_fd(symbols_u[n], 1));
		else
			return (ft_putchar_fd(symbols[n], 1));
	}
	else
	{
		count = print_hex(n / 16, spec);
		return (count + print_hex(n % 16, spec));
	}
}

int	print_dec(long long n)
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
		return (print_dec(-n) + 1);
	}
	else if (n < 10)
		return (ft_putchar_fd(symbols[n], 1));
	else
	{
		count = print_dec(n / 10);
		return (count + print_dec(n % 10));
	}
}
