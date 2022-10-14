### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
/**
 * It taken the forks
 * 
 * @param philo a pointer to a t_philo struct
 * 
 * @return a void.
 */
void	philo_fork_lock(t_philo *philo)
{
	if (check_stop(philo->data))
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->data->printer_mutex);
		if (check_stop(philo->data))
			printf ("%lli %i has taken a fork\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer_mutex);
		if (philo->data->number_of_philosophers == 1)
		{
			while (check_stop(philo->data))
				usleep(1000);
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		pthread_mutex_lock(&philo->prev->fork);
		pthread_mutex_lock(&philo->data->printer_mutex);
		if (check_stop(philo->data))
			printf ("%lli %i has taken a fork\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer_mutex);
	}
}

/**
 * Unlock the forks
 * 
 * @param philo the philosopher
 */
void	philo_fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
}

/**
 * Loop for the philosopher to eat
 * 
 * @param philo a pointer to the philosopher struct
 */
void	philo_eat(t_philo *philo)
{
	if (check_stop(philo->data))
	{
		pthread_mutex_lock(&philo->data->time_to_eat_mutex);
		philo->last_time_to_eat = get_time();
		pthread_mutex_unlock(&philo->data->time_to_eat_mutex);
		pthread_mutex_lock(&philo->data->printer_mutex);
		if (check_stop(philo->data))
			printf ("%lli %i is eating\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_lock(&philo->data->eat_mutex);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->data->eat_mutex);
		eat_count_check(philo->data);
		pthread_mutex_unlock(&philo->data->printer_mutex);
		if (check_stop(philo->data))
			usleep(philo->data->time_to_eat * 1000);
	}
}

/**
 * Loop for the philosopher to sleep
 * 
 * @param philo a pointer to the philosopher struct
 */
void	philo_sleep(t_philo *philo)
{
	if (check_stop(philo->data))
	{
		pthread_mutex_lock(&philo->data->printer_mutex);
		if (check_stop(philo->data))
			printf ("%lli %i is sleeping\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer_mutex);
		if (check_stop(philo->data))
			usleep(philo->data->time_to_sleep * 1000);
	}
}

/**
 * Loop for the philosopher to think
 * 
 * @param philo a pointer to the philosopher struct
 */
void	philo_think(t_philo *philo)
{
	if (check_stop(philo->data))
	{
		pthread_mutex_lock(&philo->data->printer_mutex);
		if (check_stop(philo->data))
			printf ("%lli %i is thinking\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer_mutex);
	}
}
```