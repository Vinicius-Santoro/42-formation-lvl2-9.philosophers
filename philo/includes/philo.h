/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:04:33 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/13 13:04:33 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define RE "\033[0m"
#define INVALID_ARGV GREEN "\
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━┓\n\
┃" RED "ERROR:" RE " " GREEN "You must specify at least 4 or 5 arguments┃  Rules ┃\n\
┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃━━━━━━━━┃\n\
┃ - [1] number_of_philosophers                    ┃  >  0  ┃\n\
┃ - [2] time_to_die                               ┃  >= 0  ┃\n\
┃ - [3] time_to_eat                               ┃  >= 0  ┃\n\
┃ - [4] time_to_sleep                             ┃  >= 0  ┃\n\
┃ - [5] number_of_times_each_philosopher_must_eat ┃  >= 0  ┃\n\
┃ - Obs: Argument 5 is optional.                  ┃   --   ┃\n\
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━┛\n" RE

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
	int				number_of_eat;
	long long		start_time;
	pthread_mutex_t	printer_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	time_to_eat_mutex;
	int				stop;
	t_philo			*philo;
}	t_data;

int 		ft_isdigit(int c);
int			ft_atoi(const char *nptr);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_fork_unlock(t_philo *philo);
void		philo_fork_lock(t_philo *philo);
long long	get_time(void);
void		free_all(t_data *data);
void		death_check(t_data *data);
void		init_philo_list(t_data *data);
void		death_check(t_data *data);
void		start_threads(t_data *data);
int			check_stop(t_data *data);
int			eat_count_check(t_data *data);
int			check_eat_mutex(t_philo *philo);

#endif