/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:44:16 by spurple           #+#    #+#             */
/*   Updated: 2022/01/21 19:44:18 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	pthread_run(t_table *table)
{
	int	i;

	i = 0;
	table->start = get_time(0);
	while (i < table->all_philo)
	{
		table->idx = i;
		table->philo[i]->time_to_die = get_time(table->time_die);
		if (pthread_create(&table->philo[i]->tid, NULL, philo_life, (void *) \
		table) != 0)
		{
			printf("Tread create Error\n");
			exit(-1);
		}
		else
			pthread_detach(table->philo[i]->tid);
		usleep(10);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (validator(argc, argv))
	{
		table.all_philo = ft_atoi(argv[1]);
		philo_init(&table, argv, argc);
		pthread_run(&table);
		if (pthread_create(&table.tid, NULL, monitoring, (void *) &table) != 0)
		{
			printf("Tread create Error\n");
			exit(-1);
		}
		else
			pthread_join(table.tid, NULL);
		clear(&table);
	}
	else
		printf("Error\n");
	return (0);
}
