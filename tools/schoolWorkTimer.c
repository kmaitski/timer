/*
 * =============================================================================
 *
 *       Filename:  schoolWorkTimer.c
 *
 *    Description:  This will be the main function to keep track of my school
 *   		 		work and do all of the I/O stuff that is necessary.
 *
 *        Version:  1.0
 *        Created:  08/08/2017 15:49:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Maitski (KM), kevin.maitski@gmail.com
 *   Organization:  42
 *
 * =============================================================================
 */

#include "timer.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  schoolWorkTimer
 *  Description:  This function will change the string into an int and will add
 *  			  it to a file.
 * =============================================================================
 */
void	schoolWorkTimer(char *code)
{
	int 	minutesWorked = atoi(code);
	FILE	*dailyMinutesWorked = fopen("dailyMinutesWorked.txt", "a");

	fprintf("%i", minutesWorked)


}		/* -----  end of function schoolWorkTimer  ----- */
