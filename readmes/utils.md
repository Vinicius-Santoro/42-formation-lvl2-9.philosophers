### _Project 9: Philosophers - Ninth project for the formation of software engineers at school 42 São Paulo._

🏠 [home](https://github.com/Vinicius-Santoro/42-formation-lvl2-9.philosophers) &nbsp;&nbsp;&nbsp;

```c
/**
 * It returns the current time in milliseconds.
 * 
 * @return The time in milliseconds.
 */
long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

/**
 * It checks if the character is a digit.
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
 * @param string This is the string that we are going to convert to an integer.
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
		final_return = (final_return * 10) + (*string - '0');
		string++;
	}
	return (final_return * signal);
}
```