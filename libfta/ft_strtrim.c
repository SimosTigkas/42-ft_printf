/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:46:48 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/20 16:36:01 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*create_final(char const *s, int start, int len);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		final_len;
	char	*final;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]))
		j--;
	final_len = j - i + 1;
	if (final_len < 0)
		final_len = 0;
	final = create_final(s1, i, final_len);
	return (final);
}

static char	*create_final(char const *s, int start, int len)
{
	char	*final;
	int		i;

	i = 0;
	final = malloc(len + 1);
	if (!final)
		return (NULL);
	while (i < len && len > 0)
	{
		final[i] = s[start + i];
		i++;
	}
	final[len] = '\0';
	return (final);
}
