#include "philo.h"

void	philo_init(t_table *table, char **argv, int flag)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->all_philo);
	while (i < table->all_philo)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		table->philo[i]->philo_num = i;
		table->philo[i]->time_die = ft_atoi(argv[2]);
		table->philo[i]->time_eat = ft_atoi(argv[3]);
		table->philo[i]->time_sleep = ft_atoi(argv[4]);
		if (flag == 6)
			table->philo[i]->nte = ft_atoi(argv[5]);
		i++;
	}
}

void	*check(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	printf("tread %d\n", philo.time_die);
	return NULL;
}

void	pthread_run(t_philo *philo)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, check, &philo);
	pthread_join(tid, NULL);
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
		while (++i < table.all_philo)
			pthread_run(table.philo[i]);
	}
	else
		printf("Error\n");
	return (0);
}
