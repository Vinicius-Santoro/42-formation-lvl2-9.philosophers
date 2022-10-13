/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:02:43 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/13 13:02:43 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_all(t_data *data)
{
	if (data->philo_num == 1)
	{
		free(data->philo);
		free (data);
	}
	else
	{
		while (data->philo_num > 1)
		{
			data->philo = data->philo->next;
			free (data->philo->prev);
			data->philo_num--;
		}
		free(data->philo);
		free(data);
	}
}
