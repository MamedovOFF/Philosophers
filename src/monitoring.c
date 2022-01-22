/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:44:23 by spurple           #+#    #+#             */
/*   Updated: 2022/01/22 12:23:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_nte(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->all_philo)
	{
		if (table->nte != table->philo[i]->nte)
			return (0);
		i++;
	}
	return (1);
}

void	monitoring(t_table *table)
{
	int	i;
	int	ok;

	ok = 1;
	while (ok == 1)
	{
		i = 0;
		while (i < table->all_philo)
		{
			if (get_time(0) > table->philo[i]->time_to_die)
			{
				print_mutex(table, i, "died");
				ok = 0;
				break ;
			}
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
}
