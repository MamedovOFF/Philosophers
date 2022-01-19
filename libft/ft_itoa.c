/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:39:37 by spurple           #+#    #+#             */
/*   Updated: 2021/10/16 20:39:37 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len] = 48 + (n % 10);
		n /= 10;
		len--;
	}
	return (str);
}
