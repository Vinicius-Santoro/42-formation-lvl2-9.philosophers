```c
#include "../includes/philo.h"

/**
 * It locks the forks of the philosopher and prints a message
 * 
 * @param philo a pointer to a t_philo struct
 * 
 * @return the time in milliseconds.
 */
void	philo_fork_lock(t_philo *philo)
{
	if (philo->data->dead_management == 0)
	{
		/* It locks the forks of the philosopher and prints a message */
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i has taken a fork\n", get_time() \
					- philo->data->start_time, philo->id);

		/* Unlocking the mutex and then checking if the number of philosophers is 1. If
		it is, it sleeps for the time to die and then returns. */
		pthread_mutex_unlock(&philo->data->printer);
		if (philo->data->number_of_philosophers == 1)
		{
			usleep(philo->data->time_to_die * 1000);
			return ;
		}
		/* It locks the forks of the philosopher and prints a message */
		pthread_mutex_lock(&philo->prev->fork);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i has taken a fork\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
	}
}

/**
 * Unlock the mutex.*
 * 
 * @param philo the philosopher
 */
void	philo_fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
}

/**
 * It locks the death mutex, locks the printer, prints that the philosopher is
 * eating, increments the eat count, unlocks the printer, unlocks the death mutex,
 * and then sleeps for the time to eat
 * 
 * @param philo a pointer to the philosopher
 */
void	philo_eat(t_philo *philo)
{
	if (philo->data->dead_management == 0)
	{
		philo->last_time_to_eat = get_time();
		pthread_mutex_lock(&philo->data->death_mutex);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i is eating\n", get_time() \
					- philo->data->start_time, philo->id);
		philo->eat_count++;
		pthread_mutex_unlock(&philo->data->printer);
		pthread_mutex_unlock(&philo->data->death_mutex);
		usleep(philo->data->time_to_eat * 1000);
	}
}

/**
 * It prints that the philosopher is sleeping, then sleeps for the amount of time
 * specified by the user
 * 
 * @param philo a pointer to a t_philo struct
 */
void	philo_sleep(t_philo *philo)
{
	if (philo->data->dead_management == 0)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i is sleeping\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
		pthread_mutex_unlock(&philo->data->death_mutex);
		if (philo->data->dead_management == 0)
			usleep(philo->data->time_to_sleep * 1000);
	}
}

/**
 * It prints a message to the console if the philosopher is still alive
 * 
 * @param philo a pointer to a t_philo struct
 */
void	philo_think(t_philo *philo)
{
	if (philo->data->dead_management == 0)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		pthread_mutex_lock(&philo->data->printer);
		if (philo->data->dead_management == 0)
			printf ("%lli %i is thinking\n", get_time() \
					- philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->data->printer);
		pthread_mutex_unlock(&philo->data->death_mutex);
	}
}
```