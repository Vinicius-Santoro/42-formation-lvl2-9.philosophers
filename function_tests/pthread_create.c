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


// int mails = 0;
// pthread_mutex_t mutex;

// void	*routine()
// {
//     for (int i = 0; i < 10000000; i++)
// 	{
//         pthread_mutex_lock(&mutex);
//         mails++;
//         pthread_mutex_unlock(&mutex);
//     }
// }

// int	main()
// {
// 	pthread_t thread[4];
// 	pthread_mutex_init(&mutex, NULL);
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
// 		{
// 			perror("Failed to create thread\n");
// 			return (1);
// 		}
// 		printf("Thread %d has started\n", i);
// 	}
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (pthread_join(thread[i], NULL) != 0)
// 			return (2);
// 		printf("Thread %d has finished execution\n", i);
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("Number of mails: %d\n", mails);
// 	return (0);
// }

void	*routine()
{
	printf("Hello from thread!\n");
	sleep(3);
	printf("Ending thread\n");
}

int	main()
{
	pthread_t thread[2];
	int i;

	for(i = 0; i < 2; i++)
		pthread_create(thread + i, NULL, routine, NULL);
	for(i = 0; i < 2; i++)
		pthread_join(thread[i], NULL);

	return(0);
}