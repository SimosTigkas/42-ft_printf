/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:37:36 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/20 16:32:31 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		neg;
	long	prev;

	i = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		prev = nb;
		nb = 10 * nb + str[i] - '0';
		if (nb < 0 && neg < 0)
			return (0);
		else if (((nb < 0) || prev > nb) && neg > 0)
			return (-1);
		i++;
	}
	return (nb * neg);
}
