#ifndef  PHILO_H
# define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include "libft/libft.h"

typedef struct s_philo
{
	int		philo_num;
	int		time_die;
	int		time_sleep;
	int		time_eat;
	int		time_fork;
	unsigned int	left;
	unsigned int	right;
	int		nte;
}	t_philo;
typedef struct s_table
{
	int			all_philo;
	t_philo		**philo;
}	t_table;
#endif