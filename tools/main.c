/*
 * =============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main for program to convert Pomodoro 25 minutes sections
 *    				into hours
 *
 *        Version:  1.0
 *        Created:  07/31/2017 14:13:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Maitski (KM), kevin.maitski@gmail.com
 *   Organization:  42
 *
 * =============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
/******************************************************
**               funtion prototypes                 ***
*******************************************************/
void logic(int *minutesWorked, int *hoursWorked, int *totalMinutesWorked);

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  main
 *  Description:  
 * =============================================================================
 */
int	main(void)
{
	int		minutesWorked = 0;
	int		hoursWorked = 0;
	char	letter = 0;
	int		totalMinutesWorked = 0;

	while (1) {
		printf("Enter I for input or T for total\n");
		scanf(" %c", &letter);
		if (letter == 'i' || letter == 'I') {
			printf("Please enter minutes worked\n");
			scanf("%d", &minutesWorked);
			logic(&minutesWorked, &hoursWorked, &totalMinutesWorked);
		}
		else if (letter == 't' || letter == 'T') {
			printf("You have worked %d hour(s) and %d minute(s).\n", hoursWorked,totalMinutesWorked);
		}
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  logic
 *  Description:  Function takes the raw amount of minutes worked and returns
 *  			  the amount of hours and minutes
 * =============================================================================
 */
void	logic(int *minutesWorked, int *hoursWorked, int *totalMinutesWorked)
{
//	int totalHoursWorked;

	*totalMinutesWorked += *minutesWorked;
	if (*totalMinutesWorked >= 60) {
		*hoursWorked += *totalMinutesWorked / 60;
		*totalMinutesWorked = *totalMinutesWorked % 60;
	}
}		/* -----  end of function logic  ----- */
