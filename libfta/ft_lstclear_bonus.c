/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:38:08 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/10 10:56:58 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!(*lst) || !del || !(lst))
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		(del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
