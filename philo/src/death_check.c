/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:14:36 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 20:14:36 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	eat_count_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (philo->eat_count != data->number_eat)
		return (0);
	philo = philo->next;
	while (philo != data->philo)
	{
		if (philo->eat_count != data->number_eat)
			return (0);
		philo = philo->next;
	}
	data->dead = 1;
	return (1);
}

void	death_check(t_data *data)
{
	t_philo	*philo;

	usleep ((data->time_to_die * 1000) - 10);
	philo = data->philo;
	while (data->dead == 0)
	{
		if (eat_count_check(data))
			break ;
		pthread_mutex_lock(&data->death_mutex);
		if (get_time() - philo->last_time_to_eat > data->time_to_die)
		{
			printf ("%lli %i died\n", get_time() - data->start_time, philo->id);
			data->dead = 1;
		}
		pthread_mutex_unlock(&data->death_mutex);
		philo = philo->next;
	}
}
