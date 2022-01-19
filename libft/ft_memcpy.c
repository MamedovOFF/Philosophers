/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:03:49 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 17:59:07 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t	i;
	char	*des;
	char	*src;

	i = 0;
	des = (char *)destination;
	src = (char *)source;
	if (des || src)
	{
		while (i < n)
		{
			*(des + i) = *(src + i);
			i++;
		}
	}
	return (destination);
}
