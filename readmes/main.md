```c
#include "../includes/philo.h"

/**
 * It checks if the arguments are valid
 * 
 * @param argv The array of arguments passed to the program.
 * 
 * @return the value of the variable i.
 */
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

/**
 * It returns the current time in milliseconds.
 * 
 * @return The time in milliseconds.
 */
long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

/**
 * It initializes the data structure, creates the philosophers list, starts all the
 * threads and frees the data structure
 * 
 * @param argc number of arguments
 * @param argv number_of_philosophers, time_to_die, time_to_eat, time_to_sleep,
 * number_eat
 */
int	main(int argc, char **argv)
{
	t_data	*data;

/* Checking if the number of arguments is between 5 and 6 and if the arguments are
valid. */
	if (argc < 5 || argc > 6 || check_arguments(argv) == 0)
	{
		printf ("Error: Invalid Arguments!\n");
		exit (1);
	}
	data = (t_data *) malloc (sizeof(t_data));
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead_management = 0;
	if (argv[5] != NULL)
		data->number_eat = ft_atoi(argv[5]);
	else
		data->number_eat = -1;

	/* Creating a list of philosophers. */
	init_philosophers_list(data);

	/* Creating the threads. */
	start_all_threads(data);

	/* Freeing the data structure. */
	free_all(data);
}
```
