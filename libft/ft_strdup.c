/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:48:09 by spurple           #+#    #+#             */
/*   Updated: 2021/10/16 20:54:24 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = (char *)malloc(sizeof(*str) * ft_strlen(str) + 1);
	if (!str1)
		return (NULL);
	while (str[i])
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = 0;
	return (str1);
}
