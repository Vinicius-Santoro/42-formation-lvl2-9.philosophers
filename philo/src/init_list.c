/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:02:53 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/13 13:02:53 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	add_to_list(t_philo *philo, t_data *data, int n)
{
	t_philo	*new_philo;
	t_philo	*first;

	first = philo;
	new_philo = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&new_philo->fork, NULL);
	new_philo->id = n + 1;
	new_philo->data = data;
	new_philo->eat_count = 0;
	while (philo->next != first)
		philo = philo->next;
	philo->next = new_philo;
	new_philo->next = first;
	new_philo->prev = philo;
	first->prev = new_philo;
}

void	init_philo_list(t_data *data)
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
		add_to_list(data->philo, data, n);
}
