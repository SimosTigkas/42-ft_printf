/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:47:36 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/20 16:34:05 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = (t_list *)malloc(sizeof(*str));
	if (!str)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
