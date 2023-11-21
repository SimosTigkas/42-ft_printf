/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:27:56 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/21 11:27:20 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_u(unsigned int n)
{
	int		c;

	c = 0;
	if (n >= 10)
	{
		c = h(c, print_u(n / 10));
		if (c == -1)
			return (-1);
	}
	c = h(c, ft_putchar_fd(n % 10 + '0', 1));
	if (c == -1)
		return (-1);
	return (c);
}

int	print_hex(unsigned long n, char spec)
{
	int		c;

	c = 0;
	if (n < 16)
	{
		if (n < 10)
			return (h(c, ft_putchar_fd(n + '0', 1)));
		else
		{
			if (spec == 'X')
				return (h(c, ft_putchar_fd(n - 10 + 'A', 1)));
			else
				return (h(c, ft_putchar_fd(n - 10 + 'a', 1)));
		}
	}
	else
	{
		c = h(c, print_hex(n / 16, spec));
		if (c == -1)
			return (-1);
		c = h(c, print_hex(n % 16, spec));
		if (c == -1)
			return (-1);
		return (c);
	}
}
