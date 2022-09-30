### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
#include "../includes/philo.h"

/**
 * If the character is a digit, return 1, otherwise return 0
 * 
 * @param c The character to be checked.
 * 
 * @return 1 or 0
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/**
 * It converts a string to an integer.
 * 
 * @param string The string to be converted.
 * 
 * @return the integer value of the string.
 */
int	ft_atoi(const char *string)
{
	int	signal;
	int	final_return;

	signal = 1;
	final_return = 0;
	while (*string == ' ' || *string == '\n' || *string == '\t'
		|| *string == '\v' || *string == '\f' || *string == '\r')
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			signal = -1;
		string++;
	}
	while (ft_isdigit(*string))
	{
		/* Converting the string to an integer. */
		final_return = (final_return * 10) + (*string - '0');
		string++;
	}
	return (final_return * signal);
}
```