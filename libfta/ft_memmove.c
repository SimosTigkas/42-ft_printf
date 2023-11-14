/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:44:35 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/06 14:54:27 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest1;
	const char	*srcc;

	i = 0;
	dest1 = (char *)dst;
	srcc = (const char *)src;
	if (dest1 <= srcc || dest1 >= srcc + len)
		ft_memcpy(dest1, srcc, len);
	else
	{
		i = len;
		while (i > 0)
		{
			dest1[i - 1] = srcc[i - 1];
			i--;
		}
	}
	return (dest1);
}
