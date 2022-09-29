/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:18 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/29 15:20:18 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	char *name = "Vinicius";

	write(2, name, sizeof(*name * sizeof(char)));
	return (0);
} 