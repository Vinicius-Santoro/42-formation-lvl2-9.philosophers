/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:14:56 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 20:14:56 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	add_philosophers_to_list(t_philo *philo, t_data *data, int n)
{
	t_philo	*new_philosophers;
	t_philo	*first;

	first = philo;
	new_philosophers = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&new_philosophers->fork, NULL);
	new_philosophers->id = n + 1;
	new_philosophers->data = data;
	new_philosophers->eat_count = 0;
	while (philo->next != first)
		philo = philo->next;
	philo->next = new_philosophers;
	new_philosophers->next = first;
	new_philosophers->prev = philo;
	first->prev = new_philosophers;
}

void	init_philosophers_list(t_data *data)
{
	int	n;

	data->philo = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&data->philo->fork, NULL);
	data->philo->data = data;
	data->philo->id = 1;
	data->philo->eat_count = 0;
	data->philo->next = data->philo;
	data->philo->prev = data->philo;
	n = 0;
	while (++n < data->number_of_philosophers)
		add_philosophers_to_list(data->philo, data, n);
}
