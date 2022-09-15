/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:02:06 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/15 19:02:06 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
Usleep library
*/
#include <unistd.h>

int main(void)
{
    unsigned int mSeconds;
    int returnCode;

    printf("Insert the microseconds: ");
    scanf("%d", &mSeconds);

    printf("The value insered is: %d\n", mSeconds);

    returnCode = usleep(mSeconds);
    if(!returnCode)
        printf("Sucess execution!\nExit code: %d\n", returnCode);
    else
        printf("Failure execution!\nExit code: %d\n", returnCode);
    return (0);
} 