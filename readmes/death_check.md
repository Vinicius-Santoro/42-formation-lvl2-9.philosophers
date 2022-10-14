### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
/**
 * It checks if the number of times a philosopher has eaten is equal to the number
 * of times he should eat
 * 
 * @param data a pointer to a struct containing all the data for the program
 * 
 * @return 0 or 1
 */
int	eat_count_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (check_eat_mutex(philo))
		return (0);
	philo = philo->next;
	while (philo != data->philo)
	{
		if (check_eat_mutex(philo))
			return (0);
		philo = philo->next;
	}
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
	return (1);
}

/**
 * It checks if the philosopher is dead
 * 
 * @param data a pointer to a t_data struct, which contains all the information
 * about the simulation.
 */
void	death_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	usleep(5000);
	while (check_stop(data))
	{
		usleep(10);
		pthread_mutex_lock(&philo->data->time_to_eat_mutex);
		if (get_time() - philo->last_time_to_eat > data->time_to_die)
		{
			pthread_mutex_unlock(&philo->data->time_to_eat_mutex);
			pthread_mutex_lock(&data->stop_mutex);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			pthread_mutex_lock(&data->printer_mutex);
			printf ("%lli %i died\n", get_time() - data->start_time, philo->id);
			pthread_mutex_unlock(&data->printer_mutex);
			break ;
		}
		else
			pthread_mutex_unlock(&philo->data->time_to_eat_mutex);
		philo = philo->next;
	}
}
```