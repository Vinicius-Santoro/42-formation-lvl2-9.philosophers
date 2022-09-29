/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:22:54 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 16:22:54 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * It creates a circular linked list of philosophers.
 * 
 * @param philosopher a pointer to the first philosopher in the linked list
 * @param data a struct that contains the number of philosophers, the number of
 * times they must eat, and the time to sleep
 * @param i the number of philosophers
 */
static void	add_to_linked_list(t_philo *philosopher, t_data *data, int i)
{
	t_philo	*new_philosopher;
	t_philo	*head;

	head = philosopher;
	new_philosopher = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&new_philosopher->fork, NULL);
	new_philosopher->identification = i + 1;
	new_philosopher->umber_of_eat = 0;
	while (philosopher->next != head)
		philosopher = philosopher->next;
	philosopher->next = new_philosopher;
	new_philosopher->next = head;
	new_philosopher->prev = philosopher;
	head->prev = new_philosopher;
}

/**
 * It creates a circular linked list of philosophers
 * 
 * @param data a pointer to the data structure.
 */
void	init_philo_list(t_data *data)
{
	int	i;

	data->philosophers = (t_philosophers *) malloc (sizeof(t_philosophers));
	/*
    Initializing a mutex.
    */
    pthread_mutex_init(&data->philosophers->fork, NULL);
	data->philosophers->identification = 1;
	data->philosophers->number_of_eat = 0;
	data->philosophers->next = data->philosophers;
	data->philosophers->prev = data->philosophers;
	i = 0;
	while (++i < data->philosophers_num)
		add_to_linked_list(data->philosophers, data, i);
}