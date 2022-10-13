/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:02:38 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/13 13:02:38 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat_count_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (check_eat_mutex(philo))
		return (0);
	philo = philo->next;
	while (philo != data->philo)
	{
		if (check_eat_mutex(philo))
			return (0);
		philo = philo->next;
	}
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
	return (1);
}

void	death_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	usleep(5000);
	while (check_stop(data))
	{
		usleep(10);
		pthread_mutex_lock(&philo->data->time_to_eat_mutex);
		if (get_time() - philo->last_time_to_eat > data->time_to_die)
		{
			pthread_mutex_unlock(&philo->data->time_to_eat_mutex);
			pthread_mutex_lock(&data->stop_mutex);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			pthread_mutex_lock(&data->printer_mutex);
			printf ("%lli %i died\n", get_time() - data->start_time, philo->id);
			pthread_mutex_unlock(&data->printer_mutex);
			break ;
		}
		else
			pthread_mutex_unlock(&philo->data->time_to_eat_mutex);
		philo = philo->next;
	}
}
