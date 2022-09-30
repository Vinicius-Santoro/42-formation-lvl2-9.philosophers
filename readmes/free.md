```c
#include "../includes/philo.h"

/**
 * It frees the data structure and the linked list of philosophers
 * 
 * @param data a pointer to a t_data struct
 */
void	free_all(t_data *data)
{
	if (data->number_of_philosophers == 1)
	{
		free(data->philo);
		free (data);
	}
	else
	{
		while (data->number_of_philosophers > 1)
		{
			data->philo = data->philo->next;
			free (data->philo->prev);
			data->number_of_philosophers--;
		}
		free(data->philo);
		free(data);
	}
}
```