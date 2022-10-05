/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:15:05 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 20:15:05 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_fork_lock(t_philo *philo)
{
	if (philo->data->dead_management == 0)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i has taken a fork\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
		if (philo->data->number_of_philosophers == 1)
		{
			usleep((philo->data->time_to_die * 1000) + 1000);
			return ;
		}
		pthread_mutex_lock(&philo->prev->fork);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i has taken a fork\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
	}
}

void	philo_fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	philo_eat(t_philo *philo)
{
	if (philo->data->dead_management == 0)
	{
		philo->last_time_to_eat = get_time();
		pthread_mutex_lock(&philo->data->death_mutex);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i is eating\n", get_time() \
					- philo->data->start_time, philo->id);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->data->printer);
		pthread_mutex_unlock(&philo->data->death_mutex);
		usleep(philo->data->time_to_eat * 1000);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (philo->data->dead_management == 0)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i is sleeping\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
		pthread_mutex_unlock(&philo->data->death_mutex);
		if (philo->data->dead_management == 0)
			usleep(philo->data->time_to_sleep * 1000);
	}
}

void	philo_think(t_philo *philo)
{
	if (philo->data->dead_management == 0)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i is thinking\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
		pthread_mutex_unlock(&philo->data->death_mutex);
	}
}
