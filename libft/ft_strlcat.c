/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:14:25 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 18:02:40 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	deslen;
	size_t	srclen;

	i = 0;
	deslen = ft_strlen(destination);
	srclen = ft_strlen(src);
	n = deslen;
	if (size > 0)
	{
		while ((deslen + i < size - 1) && src[i])
		{
			destination[n] = src[i];
			i++;
			n++;
		}
		destination[n] = 0;
	}
	if (deslen >= size)
		deslen = size;
	return (deslen + srclen);
}
