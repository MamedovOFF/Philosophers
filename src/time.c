/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:44:36 by spurple           #+#    #+#             */
/*   Updated: 2022/01/21 19:44:37 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	get_time(long i)
{
	long			time;
	struct timeval	s_tm;

	gettimeofday(&s_tm, NULL);
	time = (s_tm.tv_sec % 1000) * 1000;
	time += s_tm.tv_usec / 1000;
	return (time + i);
}

void	smart_sleep(int time)
{
	long	t;

	t = get_time(0);
	while (get_time(0) - t < time)
	{
		usleep(1);
	}
}
