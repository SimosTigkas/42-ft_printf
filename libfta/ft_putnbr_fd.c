/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:16:23 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/20 16:37:58 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	c;

	c = 0;
	if (n == -2147483648)
		return (h(c, write(fd, "-2147483648", 11)));
	if (n < 0)
	{
		c = h(c, ft_putchar_fd('-', fd));
		if (c == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		c = h(c, ft_putnbr_fd(n / 10, fd));
		if (c == -1)
			return (-1);
	}
	c = h(c, ft_putchar_fd(n % 10 + '0', fd));
	if (c == -1)
		return (-1);
	return (c);
}
