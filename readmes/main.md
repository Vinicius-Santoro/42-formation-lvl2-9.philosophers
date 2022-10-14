### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
/**
 * It checks if the arguments are valid
 * 
 * @param argv The array of strings passed to the program.
 * 
 * @return the value of the variable i.
 */
static int	check_arguments(char **argv)
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
 * It initializes the data structure, creates the philosophers, and starts the
 * threads
 * 
 * @param argc number of arguments
 * @param argv number of philosophers, time to die, time to eat, time to sleep,
 * number of times each philosopher must eat (optional)
 */
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
	data->stop = 0;
	if (argv[5] != NULL)
		data->number_of_eat = ft_atoi(argv[5]);
	else
		data->number_of_eat = -1;
	init_philo_list(data);
	start_threads(data);
	free_all(data);
}
```