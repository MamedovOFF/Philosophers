/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:49:25 by spurple           #+#    #+#             */
/*   Updated: 2022/01/21 19:51:23 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_num;
	int				flag;
	int				time_to_die;
	int				nte;
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
	pthread_mutex_t	print;
	t_philo			**philo;
}	t_table;
int		check_all_nte(t_table *table);
void	monitoring(t_table *table);
long	get_time(long i);
void	smart_sleep(int time);
void	print_mutex(t_table *table, int i, char *str);
void	*philo_life(void *arg);
int		validator(int argc, char **argv);
void	philo_init(t_table *table, char **argv, int flag);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int arg);

#endif
