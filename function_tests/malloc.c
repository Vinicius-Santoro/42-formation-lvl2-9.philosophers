/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:16:47 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/14 23:16:47 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
Malloc library
*/
#include <stdlib.h>
 
int main(void)
{
    char *name;
    name = (char *) malloc(21);
 
    printf("Insert your name: ");
    gets(name);
 
    printf("%sn", name);
 
    return 0;
}
 