/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:40:31 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 17:58:07 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		tmp = temp->next;
		ft_lstdelone(temp, del);
		temp = tmp;
	}	
	*lst = NULL;
}
