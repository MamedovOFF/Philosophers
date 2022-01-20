#include "philo.h"


long	get_time(long i)
{
	long			time;
	struct timeval	s_tm;

	gettimeofday(&s_tm, NULL);
	time = (s_tm.tv_sec % 1000) * 1000;
	time += s_tm.tv_usec / 1000;
	return (time + i);
}


void	philo_init(t_table *table, char **argv, int flag)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->all_philo);
	while (i < table->all_philo)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		table->philo[i]->philo_num = i + 1;
		table->philo[i]->flag = 0;
		table->philo[i]->time_die = ft_atoi(argv[2]);
		table->philo[i]->time_eat = ft_atoi(argv[3]);
		table->philo[i]->time_sleep = ft_atoi(argv[4]);
		if (flag == 6)
			table->philo[i]->nte = ft_atoi(argv[5]);
		pthread_mutex_init(&table->philo[i]->forks, NULL);
		i++;
	}

}


void	*philo_life(void* arg)
{
	t_philo	*philo;
	long die;
	long eating;

	philo = (t_philo *)arg;
	philo->start = get_time(0);
	die = get_time(philo->time_die);
	eating = get_time(philo->time_eat);
	printf("Tread %d\n", philo->philo_num);
	while (1)
	{
		if (get_time(0) > die )
			philo->flag = 1;
	}
	pthread_mutex_lock(&philo->forks);
	pthread_mutex_unlock(&philo->forks);
	return NULL;
}

void	pthread_run(t_philo *philo)
{
	pthread_create(&philo->tid, NULL, philo_life, (void *)philo);
}

void monitoring(t_table *table)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < table->all_philo)
		{
			if (table->philo[i]->flag == 1)
			{
				printf("Philo %d dead\n", table->philo[i]->philo_num);
				exit(0);
			}
			i++;
		}
	}
	
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	i = 0;
	if (argc >= 5 && argc <= 6)
	{
		table.all_philo = ft_atoi(argv[1]);
		philo_init(&table, argv, argc);
		while (i < table.all_philo)
			pthread_run(table.philo[i++]);
		monitoring(&table);
	}
	else
		printf("Error\n");
	return (0);
}