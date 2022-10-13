/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:02:57 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/13 13:02:57 by vnazioze         ###   ########.fr       */
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
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6 || check_arguments(argv) == 0)
	{
		printf("%s", INVALID_ARGV);
		exit (1);
	}
	data = (t_data *) malloc(sizeof(t_data));
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->number_of_eat = ft_atoi(argv[5]);
	else
		data->number_of_eat = -1;
	init_philo_list(data);
	start_threads(data);
	free_all(data);
}
