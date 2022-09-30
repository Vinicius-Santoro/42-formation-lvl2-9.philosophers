### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
#include "../includes/philo.h"

/**
 * It checks if all the philosophers have eaten the required number of times
 * 
 * @param data a pointer to a struct that contains all the information about the
 * philosophers
 * 
 * @return the value of the variable dead_management.
 */
static int	eat_count_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (philo->eat_count != data->number_eat)
		return (0);
	philo = philo->next;
	while (philo != data->philo)
	{
		if (philo->eat_count != data->number_eat)
			return (0);
		philo = philo->next;
	}
	data->dead_management = 1;
	return (1);
}

/**
 * It checks if the time since the last time a philosopher ate is greater than the
 * time to die. If it is, it prints that the philosopher died and sets the dead
 * management flag to 1
 * 
 * @param data a struct that contains all the information about the philosophers
 * and the program
 */
void	death_check(t_data *data)
{
	t_philo	*philo;

	usleep ((data->time_to_die * 1000) - 10);
	philo = data->philo;
	while (data->dead_management == 0)
	{
		if (eat_count_check(data))
			break ;
		pthread_mutex_lock(&data->death_mutex);

		/* Checking if the time since the last time a philosopher ate is greater than the
		
		 * time to die. If it is, it prints that the philosopher died and sets the
		dead
		 * management flag to 1 */
		if (get_time() - philo->last_time_to_eat > data->time_to_die)
		{
			printf ("%lli %i died\n", get_time() - data->start_time, philo->id);
			data->dead_management = 1;
		}

		/* It unlocks the mutex. */
		pthread_mutex_unlock(&data->death_mutex);
		philo = philo->next;
	}
}
```