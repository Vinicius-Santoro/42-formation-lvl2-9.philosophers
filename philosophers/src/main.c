/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:18 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 15:20:18 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_arguments(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != NULL)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

    /*
    Argv Validation:
    1 - number_of_philosophers
    2 - time_to_die
    3 - time_to_eat
    4 - time_to_sleep
    5 - [number_of_times_each_philosopher_must_eat]
    */
	if ((argc < 5 || argc > 6) || (check_arguments(argv) == 0))
        write(2, "Error: Invalid Arguments!", sizeof(26));
	data = (t_data *) malloc (sizeof(t_data));
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead_management = 0;
	if (argv[5] != NULL)
		data->number_of_eat = ft_atoi(argv[5]);
	else
    /*
    -1 instead of 0 because the user might type zero in the terminal. 0 == NULL.
    */
		data->number_of_eat = -1;
	init_philo_list(data);
	start_threads(data);
	free_all(data);
}