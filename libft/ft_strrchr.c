/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:54:24 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 18:23:15 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*strr;

	strr = (char *) str;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (strr[i] == (char)ch)
			return (&strr[i]);
		i--;
	}
	return (NULL);
}
