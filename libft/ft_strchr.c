/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:39:30 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 18:23:51 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*strr;

	i = 0;
	strr = (char *) str;
	while (strr[i])
	{
		if (strr[i] == (char)ch)
			return (&strr[i]);
		i++;
	}
	if (strr[i] == ch)
		return (&strr[i]);
	return (NULL);
}
