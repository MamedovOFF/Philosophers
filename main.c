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

void	smart_sleep(int time)
{
	long	t;

	t = get_time(0);
	while (get_time(0) - t < time)
	{
		usleep(1);
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

void print_mutex(t_table *table, int i, char *str)
{
		pthread_mutex_lock(&table->print);	
		printf("%ld %d %s\n", get_time(0) - table->start,table->philo[i]->philo_num, str);
		pthread_mutex_unlock(&table->print);
}

void	*philo_life(void* arg)
{
	t_table	*table;
	int		left;
	int		i;

	table = (t_table *)arg;
	i = table->idx;
	while (1)
	{
		if (table->philo[i]->philo_num % 2)
			usleep(1500);
		if (i == 0)
			left = table->all_philo - 1;
		else				
			left = i - 1;
		pthread_mutex_lock(&table->philo[i]->fork);
		pthread_mutex_lock(&table->philo[left]->fork);
		print_mutex(table, i, "is has taken a fork");
		print_mutex(table, i, "is has taken a fork");
		print_mutex(table, i, "is eating");
		smart_sleep(table->time_eat);
		if (table->nte > 0)
			table->philo[i]->nte++;
		table->philo[i]->time_to_die = get_time(table->time_die);
		print_mutex(table, i, "is sleeping");
		pthread_mutex_unlock(&table->philo[i]->fork);
		pthread_mutex_unlock(&table->philo[left]->fork);
		smart_sleep(table->time_sleep);
		print_mutex(table, i, "is thinking");
	}
	return NULL;
}

void	pthread_run(t_table *table)
{
	int i;

	i = 0;
	table->start = get_time(0);
	while (i < table->all_philo)
	{
		table->idx = i;
		table->philo[i]->start = get_time(0);
		table->philo[i]->time_to_die = get_time(table->time_die);
		pthread_create(&table->philo[i]->tid, NULL, philo_life, (void *)table);
		pthread_detach(table->philo[i]->tid);
		usleep(10);
		i++;
	}

}

void	monitoring(t_table *table)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < table->all_philo)
		{
			if (get_time(0) > table->philo[i]->time_to_die)
			{
				printf("%ld %d died\n", get_time(0) - table->start,
					   table->philo[i]->philo_num);
				exit(0);
			}
			if (table->philo[i]->nte == table->nte)
			{
				printf("End %d %d\n", table->philo[i]->philo_num, table->philo[i]->nte);
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
		pthread_run(&table);
		monitoring(&table);
	}
	else
		printf("Error\n");
	return (0);
}