/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:34:37 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/18 23:34:37 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
Pthread_create Library
*/
#include <pthread.h>


void    *routine()
{
    printf("Test from threads\n");
	sleep(3);
	printf("Ending thread\n");
}

int	main()
{
	pthread_t thread1;
	pthread_t thread2;

	if (pthread_create(&thread1, NULL, &routine, NULL) != 0)
	{
		return (1);
	}
	if (pthread_create(&thread2, NULL, &routine, NULL) != 0)
	{
		return (2);
	}
	if (pthread_join(thread1, NULL) != 0)
	{
		return (3);
	}
	if (pthread_join(thread2, NULL) != 0)
	{
		return (4);
	}

	return (0);
}