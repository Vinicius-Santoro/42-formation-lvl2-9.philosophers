/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:03:02 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/13 13:13:24 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	if (data->stop == 1)
	{
		pthread_mutex_unlock(&data->stop_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->stop_mutex);
	return (1);
}

int	check_eat_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_mutex);
	if (philo->eat_count != philo->data->number_of_eat)
	{
		pthread_mutex_unlock(&philo->data->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->eat_mutex);
	return (0);
}
