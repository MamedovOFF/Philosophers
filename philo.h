#ifndef  PHILO_H
# define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include "libft/libft.h"

typedef struct s_philo
{
	int				philo_num;
	int				flag;
	int				time_to_die;
	long			start;
	pthread_mutex_t	fork;
	pthread_t		tid;
}	t_philo;

typedef struct s_table
{
	int				all_philo;
	int				idx;
	int				time_sleep;
	int				time_eat;
	int				time_fork;
	long			start;
	int				nte;
	int				time_die;
	pthread_mutex_t print;
	t_philo			**philo;
}	t_table;
#endif