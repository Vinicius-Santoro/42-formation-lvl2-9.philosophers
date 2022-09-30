/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:15:10 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 20:15:10 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*philosophers_management(t_philo *philo)
{
	philo->last_time_to_eat = get_time();
	if (philo->id % 2 == 0)
		usleep((philo->data->time_to_eat - 10) * 1000);
	while (philo->data->dead_management == 0 && (philo->eat_count < philo->data->number_eat \
			|| philo->data->number_eat == -1))
	{
		/* It's making the philosophers eat, sleep, think and lock/unlock the forks. */
		philo_fork_lock(philo);
		philo_eat(philo);
		philo_fork_unlock(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	start_all_threads(t_data *data)
{
	int		n;
	t_philo	*temp;

	n = data->number_of_philosophers;
	temp = data->philo;
	pthread_mutex_init(&data->printer, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	data->start_time = get_time();
	while (n > 0)
	{
		pthread_create(&temp->thread, NULL, (void *)&philosophers_management, \
		 temp);
		temp = temp->next;
		n--;
	}
	death_check(data);
	n = data->number_of_philosophers;
	while (n > 0)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
		n--;
	}
}
