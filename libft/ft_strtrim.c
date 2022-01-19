/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:32:33 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 18:03:39 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	j = ft_strlen(s1) - 1;
	if (!s1)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j] && ft_strchr(set, s1[j]) && j > i)
		j--;
	str = (char *)malloc(sizeof(*s1) * (j - i + 2));
	if (!str)
		return (NULL);
	while (k <= j - i)
	{
		str[k] = s1[i + k];
		k++;
	}
	str[k] = 0;
	return (str);
}
