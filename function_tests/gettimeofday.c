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
	/*
	1 second =  1.000.000 microsecond
	1 microsecond = 0,001 milisecond

	The timeval structure contains two members, time_t variable tv_sec and suseconds_t variable tv_usec.
	The first, tv_sec, is a time_t value, the number of seconds elapsed since January 1, 1970.
	The second is a microsecond value, which the computer knows but isn’t included with the time_t value.
	*/
    struct timeval	tv;
    struct timezone	tz;
    long int		second_and_microsecond_for_milisecond;
    long double		second_and_microsecond_for_milisecond_long;

    gettimeofday(&tv,&tz);

	second_and_microsecond_for_milisecond = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    printf("Seconds since 1/1/1970.......: %lu\n",tv.tv_sec);
    printf("Microseconds.................: %ld\n",tv.tv_usec);
	printf("Seconds for Miliseconds:.....: %ld\n", (tv.tv_sec * 1000));
	printf("Microseconds for Miliseconds.: %ld\n", (tv.tv_usec / 1000));
    printf("Sec and Microsec for Milisec.: %li\n", second_and_microsecond_for_milisecond);

    second_and_microsecond_for_milisecond_long = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    printf("\n\nlong double - 16 bytes:\n");
    printf("Sec and Microsec for Milisec (Lf): %Lf\n", second_and_microsecond_for_milisecond_long);
    printf("Sec and Microsec for Milisec (LF): %LF\n", second_and_microsecond_for_milisecond_long);
    printf("Sec and Microsec for Milisec (Lg): %Lg\n", second_and_microsecond_for_milisecond_long);
    printf("Sec and Microsec for Milisec (LG): %LG\n", second_and_microsecond_for_milisecond_long);
    printf("Sec and Microsec for Milisec (Le): %Le\n", second_and_microsecond_for_milisecond_long);
    printf("Sec and Microsec for Milisec (LE): %LE\n", second_and_microsecond_for_milisecond_long);
    printf("Sec and Microsec for Milisec (La): %La\n", second_and_microsecond_for_milisecond_long);
    printf("Sec and Microsec for Milisec (LA): %LA\n", second_and_microsecond_for_milisecond_long);

    printf("Sec and Microsec for Milisec.: %ld\n", sizeof(second_and_microsecond_for_milisecond));
    printf("Sec and Microsec for Milisec.: %ld\n", sizeof(second_and_microsecond_for_milisecond_long));

    return (0);
}
