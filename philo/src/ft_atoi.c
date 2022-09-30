/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:14:52 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 20:14:52 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

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