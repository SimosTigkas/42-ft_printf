/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:16:23 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/15 14:46:39 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(unsigned int n, int fd)
{
	char	buffer[13];
	int		i;

	buffer[11] = '\0';
	if (n == 0)
		i = ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		i = ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			i = ft_putchar_fd('-', fd);
			n = n * (-1);
		}
		i = 10;
		while (n > 0)
		{
			buffer[i] = '0' + (n % 10);
			n /= 10;
			i--;
		}
		i = ft_putstr_fd(&buffer[i + 1], fd);
	}
	return (i);
}
