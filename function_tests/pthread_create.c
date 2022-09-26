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

void	*routine()
{
	printf("Hello from thread\n");
	sleep(3);
	printf("Ending thread\n");
}

int	main()
{
	pthread_t thread[2];
	int i;

	for(i = 0; i < 2; i++)
		pthread_create(&thread[i], NULL, routine, NULL);
	for(i = 0; i < 2; i++)
		pthread_join(thread[i], NULL);

	return(0);
}
