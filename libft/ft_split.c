/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:41:00 by spurple           #+#    #+#             */
/*   Updated: 2021/10/15 17:59:55 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

int	word_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char	**fill(char const *s, int words, char c, char **str)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		str[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!str[i])
			return (NULL);
		j = 0;
		while (j < len)
			str[i][j++] = *s++;
		str[i][j] = 0;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char	const *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = count_word(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	str = fill(s, words, c, str);
	return (str);
}
