/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:44:29 by spurple           #+#    #+#             */
/*   Updated: 2022/01/21 19:44:31 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_mutex(t_table *table, int i, char *str)
{
	pthread_mutex_lock(&table->print);
	printf("%ld %d %s\n", get_time(0) - table->start, \
	table->philo[i]->philo_num, str);
	pthread_mutex_unlock(&table->print);
}

void	philo_eat(t_table *table, int i)
{
	print_mutex(table, i, "is has taken a fork");
	print_mutex(table, i, "is has taken a fork");
	print_mutex(table, i, "is eating");
	smart_sleep(table->time_eat);
	if (table->nte > 0)
		table->philo[i]->nte++;
	table->philo[i]->time_to_die = get_time(table->time_die);
	print_mutex(table, i, "is sleeping");
}

void	*philo_life(void *arg)
{
	t_table	*table;
	int		left;
	int		i;

	table = (t_table *)arg;
	i = table->idx;
	while (1)
	{
		if (table->philo[i]->philo_num % 2 && table->all_philo > 3)
			usleep(1000);
		if (i == 0)
			left = table->all_philo - 1;
		else
			left = i - 1;
		pthread_mutex_lock(&table->philo[i]->fork);
		pthread_mutex_lock(&table->philo[left]->fork);
		philo_eat(table, i);
		pthread_mutex_unlock(&table->philo[i]->fork);
		pthread_mutex_unlock(&table->philo[left]->fork);
		smart_sleep(table->time_sleep);
		print_mutex(table, i, "is thinking");
	}
}

void	philo_init(t_table *table, char **argv, int flag)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->all_philo);
	table->time_eat = ft_atoi(argv[3]);
	table->time_die = ft_atoi(argv[2]);
	table->time_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&table->print, NULL);
	if (flag == 6)
		table->nte = ft_atoi(argv[5]);
	else
		table->nte = -1;
	while (i < table->all_philo)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		table->philo[i]->philo_num = i + 1;
		pthread_mutex_init(&table->philo[i]->fork, NULL);
		table->philo[i]->flag = 0;
		if (flag == 6)
			table->philo[i]->nte = 0;
		i++;
	}
}
