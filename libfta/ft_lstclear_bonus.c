/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:38:08 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/16 14:22:55 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
