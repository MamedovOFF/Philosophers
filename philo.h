#ifndef  PHILO_H
# define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include "libft/libft.h"

typedef struct s_philo
{
	int				philo_num;
	long			start;
	int				flag;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				time_fork;
	pthread_mutex_t	fork;
	pthread_t		tid;
	int				nte;
}	t_philo;

typedef struct s_table
{
	int				all_philo;
	pthread_mutex_t	*forks;
	t_philo			**philo;
}	t_table;
#endif