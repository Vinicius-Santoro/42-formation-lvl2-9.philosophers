/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:07:29 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/15 17:07:29 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write library
*/
#include <unistd.h>

int	main(void)
{
	char *name = "Vinicius";

	write(2, name, sizeof(*name * sizeof(char)));
	return (0);
} 