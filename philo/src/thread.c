/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:03:11 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/13 13:03:11 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->time_to_eat_mutex);
	philo->last_time_to_eat = get_time();
	pthread_mutex_unlock(&philo->data->time_to_eat_mutex);
	if (philo->id % 2 == 0)
		usleep((philo->data->time_to_eat - 10) * 1000);
	while (check_stop(philo->data) && (philo->eat_count < philo->data->number_of_eat \
			|| philo->data->number_of_eat == -1))
	{
		philo_fork_lock(philo);
		if (check_stop(philo->data) == 0)
			break ;
		philo_eat(philo);
		philo_fork_unlock(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	int		n;
	t_philo	*temp;

	n = data->number_of_philosophers;
	temp = data->philo;
	pthread_mutex_init(&data->printer_mutex, NULL);
	pthread_mutex_init(&data->stop_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->time_to_eat_mutex, NULL);
	data->start_time = get_time();
	while (n > 0)
	{
		pthread_create(&temp->thread, NULL, (void *)&philo_routine, temp);
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
