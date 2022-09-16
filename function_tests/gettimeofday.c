/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:27:23 by vnazioze          #+#    #+#             */
/*   Updated: 2022/09/15 19:27:23 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
Gettimeofday library
*/
#include <sys/time.h>


/*
Under time.h library.

struct timeval {
    time_t      tv_sec;     seconds 
    suseconds_t tv_usec;    microseconds 
};

struct timezone {
    int tz_minuteswest;     minutes west of Greenwich 
    int tz_dsttime;         type of DST correction 
};

*/
int main(void)
{
    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv,&tz);

    printf("Seconds since 1/1/1970: %lu\n",tv.tv_sec);
    printf("Microseconds: %ld\n",tv.tv_usec);
    printf("Minutes west of SP: %d\n",tz.tz_minuteswest);
    printf("Daylight Saving Time adjustment: %d\n",tz.tz_dsttime);
    return (0);
}