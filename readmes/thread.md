### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
#include "../includes/philo.h"

/**
 * It's a function that do the philosophers wait
 * 
 * @param philo a pointer to a struct of type t_philo
 * 
 * @return NULL
 */
static void *philosophers_management_core(t_philo *philo)
{
	philo->last_time_to_eat = get_time();
	if (philo->id % 2 == 0)
		usleep((philo->data->time_to_eat - 10) * 1000);
	return (NULL);
}

/**
 * It's a function that manages the philosophers
 * 
 * @param philo a pointer to a struct of type t_philo
 * 
 * @return NULL
 */
static void	*philosophers_management(t_philo *philo)
{
	philosophers_management_core(philo);
	while (philo->data->dead_management == 0 && (philo->eat_count < philo->data->number_eat \
			|| philo->data->number_eat == -1))
	{
		/* It's making the philosophers eat, sleep, think and lock/unlock the forks. */
		philo_fork_lock(philo);
		philo_eat(philo);
		philo_fork_unlock(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

/**
 * It creates all the threads and then waits for them to finish
 * 
 * @param data a struct that contains all the information about the philosophers
 * and the forks
 */
void	start_all_threads(t_data *data)
{
	int		n;
	t_philo	*temp;

	n = data->number_of_philosophers;
	temp = data->philo;

	/* Initializing the mutexes. */
	pthread_mutex_init(&data->printer, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);

	/* Setting the start time of the program. */
	data->start_time = get_time();

	/* Creating a thread for each philosopher. */
	while (n > 0)
	{
		pthread_create(&temp->thread, NULL, (void *)&philosophers_management, \
		 temp);
		temp = temp->next;
		n--;
	}

	/* Checking if any of the philosophers died. */
	death_check(data);
	n = data->number_of_philosophers;

	/* Waiting for all the threads to finish. */
	while (n > 0)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
		n--;
	}
}
```