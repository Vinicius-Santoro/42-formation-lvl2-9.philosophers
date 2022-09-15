/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:35:42 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/14 23:16:21 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
Memset library
*/
#include <string.h>

#define  BUF_SIZE  20
 
int main(void)
{
	char 	buffer[BUF_SIZE + 1];
	char 	*string;

	memset(buffer, 0, sizeof(buffer));
	string = (char *) memset(buffer,'A', 10);
	printf("\nBuffer contents 1: %s\n", string);
	memset(buffer + 10, 'B', 10);
	printf("\nBuffer contents 2: %s\n", buffer);
}
 