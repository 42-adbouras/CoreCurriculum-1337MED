/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:46:05 by adbouras          #+#    #+#             */
/*   Updated: 2023/12/26 12:42:12 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*chain;
	t_list	*node;
	void	*curnt;

	if (!lst || !f || !del)
		return (NULL);
	chain = NULL;
	while (lst != NULL)
	{
		curnt = f(lst->content);
		node = ft_lstnew(curnt);
		if (!node)
		{
			del(curnt);
			ft_lstclear(&chain, del);
			return (NULL);
		}
		ft_lstadd_back(&chain, node);
		lst = lst->next;
	}
	return (chain);
}
