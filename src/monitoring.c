/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:44:23 by spurple           #+#    #+#             */
/*   Updated: 2022/01/21 19:45:50 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_all_nte(t_table *table)
{
	int	i;

	i = 0;

	while (i < table->all_philo)
	{
		pthread_mutex_lock(&table->inc);
		if (table->nte != table->philo[i]->nte)
		{
			pthread_mutex_unlock(&table->inc);
			return (0);
		}
		pthread_mutex_unlock(&table->inc);
		i++;
	}
	return (1);
}

void	*monitoring(void *arg)
{
	int	i;
	int	ok;
	t_table	*table;

	ok = 1;
	table = (t_table *)arg;
	while (ok == 1)
	{
		i = 0;
		while (i < table->all_philo)
		{
			pthread_mutex_lock(&table->time);
			if (get_time(0) > table->philo[i]->time_to_die)
			{
				print_mutex(table, i, "died");
				pthread_mutex_unlock(&table->time);
				ok = 0;
				break ;
			}
			pthread_mutex_unlock(&table->time);
			if (check_all_nte(table) == 1)
			{
				pthread_mutex_lock(&table->print);
				printf("All the philosophers have eaten\n");
				ok = 0;
				break ;
			}
			i++;
		}
	}
	return NULL;
}
