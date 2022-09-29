/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:06 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 15:20:06 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philosophers
{
	int				identification;
	long long		last_eat_time;
	int				eat_count;
	pthread_t		thread;
	pthread_mutex_t	fork;
	t_philosophers	*next;
	t_philosophers	*prev;
}	t_philosophers;

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eat;
	long long		start_time;
	int				dead_management;
	t_philosophers	*philosophers;
}	t_data;