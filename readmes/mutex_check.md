### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
/**
 * It checks if the stop variable is set to 1, and if it is, it returns 0
 * 
 * @param data a pointer to the data structure that holds all the information about
 * the
 * 
 * @return The value of data->stop
 */
int	check_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	if (data->stop == 1)
	{
		pthread_mutex_unlock(&data->stop_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->stop_mutex);
	return (1);
}

/**
 * It checks if the number of times the philosopher has eaten is equal to the
 * number of times he should eat
 * 
 * @param philo the philosopher
 * 
 * @return 1 if the philo->eat_count is not equal to the number of eat.
 */
int	check_eat_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_mutex);
	if (philo->eat_count != philo->data->number_of_eat)
	{
		pthread_mutex_unlock(&philo->data->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->eat_mutex);
	return (0);
}
```