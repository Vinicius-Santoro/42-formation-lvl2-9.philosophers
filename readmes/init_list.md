### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
#include "../includes/philo.h"

/**
 * It adds a new philosopher to the list of philosophers
 * 
 * @param philo the first philosopher in the list
 * @param data a struct that contains the number of philosophers, the number of
 * times each philosopher must eat, and the time each philosopher must think and
 * eat for.
 * @param n the number of philosophers
 */
static void	add_philosophers_to_list(t_philo *philo, t_data *data, int n)
{
	t_philo	*new_philosophers;
	t_philo	*first;

	first = philo;
	new_philosophers = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&new_philosophers->fork, NULL);
	new_philosophers->id = n + 1;
	new_philosophers->data = data;
	new_philosophers->eat_count = 0;

	/* Going to the last element of the list. */
	while (philo->next != first)
		philo = philo->next;
	philo->next = new_philosophers;

	/* Making the list circular. */
	new_philosophers->next = first;
	new_philosophers->prev = philo;
	first->prev = new_philosophers;
}

/**
 * It creates a circular linked list of philosophers
 * 
 * @param data a pointer to the data structure
 */
void	init_philosophers_list(t_data *data)
{
	int	n;

	data->philo = (t_philo *) malloc (sizeof(t_philo));

	/* Initializing the mutex. */
	pthread_mutex_init(&data->philo->fork, NULL);
	data->philo->data = data;
	data->philo->id = 1;
	data->philo->eat_count = 0;
	data->philo->next = data->philo;
	data->philo->prev = data->philo;
	n = 0;

	/* Adding the philosophers to the list. */
	while (++n < data->number_of_philosophers)
		add_philosophers_to_list(data->philo, data, n);
}
```