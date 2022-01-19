/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:18:27 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 17:59:16 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	size_t		i;

	i = -1;
	dest = (char *)destination;
	source = (char *)src;
	if (dest || source)
	{
		if (dest <= source)
		{
			while (++i < n)
				*(dest + i) = *(source + i);
		}
		else
		{
			i = n;
			while (i > 0)
			{
				*(dest + i - 1) = *(source + i - 1);
				i--;
			}
		}
	}
	return (destination);
}
