### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
/**
 * Applications core. The monitor of dining philosopher.
 * 
 * @param philo a pointer to a t_philo struct
 * 
 * @return a pointer to a void.
 */
static void	*philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->time_to_eat_mutex);
	philo->last_time_to_eat = get_time();
	pthread_mutex_unlock(&philo->data->time_to_eat_mutex);
	if (philo->id % 2 == 0)
		usleep((philo->data->time_to_eat - 10) * 1000);
	while (check_stop(philo->data) && (philo->eat_count \
	< philo->data->number_of_eat || philo->data->number_of_eat == -1))
	{
		philo_fork_lock(philo);
		if (check_stop(philo->data) == 0)
			break ;
		philo_eat(philo);
		philo_fork_unlock(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

/**
 * It creates the threads and then waits for them to finish
 * 
 * @param data a struct that contains all the information about the philosophers
 * and the simulation
 */
void	start_threads(t_data *data)
{
	int		n;
	t_philo	*temp;

	n = data->number_of_philosophers;
	temp = data->philo;
	pthread_mutex_init(&data->printer_mutex, NULL);
	pthread_mutex_init(&data->stop_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->time_to_eat_mutex, NULL);
	data->start_time = get_time();
	while (n > 0)
	{
		pthread_create(&temp->thread, NULL, (void *)&philo_routine, temp);
		temp = temp->next;
		n--;
	}
	death_check(data);
	n = data->number_of_philosophers;
	while (n > 0)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
		n--;
	}
}
```