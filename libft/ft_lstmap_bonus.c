/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:38:09 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 17:58:38 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*lst_el;

	lst_el = ft_lstnew(f(lst->content));
	if (!lst_el)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	res = lst_el;
	lst = lst->next;
	while (lst)
	{
		lst_el = ft_lstnew(f(lst->content));
		if (!lst_el)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&res, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&res, lst_el);
	}
	return (res);
}
