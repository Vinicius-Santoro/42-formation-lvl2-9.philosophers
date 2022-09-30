/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:21:04 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 20:21:04 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	long long		last_time_to_eat;
	int				eat_count;
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_philo			*next;
	t_philo			*prev;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_eat;
	long long		start_time;
	pthread_mutex_t	printer;
	pthread_mutex_t	death_mutex;
	int				dead_management;
	t_philo			*philo;
}	t_data;

int	   		ft_isdigit(int c);
int			ft_atoi(const char *nptr);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_fork_unlock(t_philo *philo);
void		philo_fork_lock(t_philo *philo);
long long	get_time(void);
void		free_all(t_data *data);
void		death_check(t_data *data);
void		init_philosophers_list(t_data *data);
void		death_check(t_data *data);
void		start_all_threads(t_data *data);
#endif