/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:54:38 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/16 14:24:58 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	end;

	i = ft_strlen(s);
	end = i;
	while (i > 0)
	{
		if (s[i -1] == (char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)&s[end]);
	return (NULL);
}
