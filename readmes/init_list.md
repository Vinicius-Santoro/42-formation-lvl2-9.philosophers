### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;


```c
#include "../includes/philo.h"

/**
 * It creates a new node, initializes it, and adds it to the circular linked list
 * 
 * @param philo a pointer to the first element of the list
 * @param data a struct that contains the number of philosophers, the number of
 * times each philosopher must eat, and the time to sleep
 * @param n the number of philosophers
 */
static void	add_to_list(t_philo *philo, t_data *data, int n)
{
	t_philo	*new_philo;
	t_philo	*first;

	first = philo;
	new_philo = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&new_philo->fork, NULL);
	new_philo->id = n + 1;
	new_philo->data = data;
	new_philo->eat_count = 0;
	while (philo->next != first)
		philo = philo->next;
	philo->next = new_philo;
	new_philo->next = first;
	new_philo->prev = philo;
	first->prev = new_philo;
}

/**
 * It creates a circular linked list of philosophers
 * 
 * @param data a pointer to the data structure
 */
void	init_philo_list(t_data *data)
{
	int	n;

	data->philo = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&data->philo->fork, NULL);
	data->philo->data = data;
	data->philo->id = 1;
	data->philo->eat_count = 0;
	data->philo->next = data->philo;
	data->philo->prev = data->philo;
	n = 0;
	while (++n < data->number_of_philosophers)
		add_to_list(data->philo, data, n);
}
```