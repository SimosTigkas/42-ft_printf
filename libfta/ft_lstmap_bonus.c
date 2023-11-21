/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:40:59 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/20 16:34:00 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	new_node = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		new_node = ft_lstnew(tmp);
		if (!(new_node))
		{
			if (tmp)
				free(tmp);
			ft_lstclear(&(new_list), del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
