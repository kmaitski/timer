/*
 * =============================================================================
 *
 *       Filename:  addMinutesWorked.c
 *
 *    Description:  Add the minutes in a text file.  Flag 1 is used for school
 *    daily minutes; flag 2 is used for house daily minutes; flag 3 is used for
 *    school weekly minutes; flag 4 house weekly minutes; flag 5 is used for
 *    monthly school minutes; flag 6 is used for monthly house minutes; flag 7
 *    is used for yearly school minutes; flag 8 is used for yearly house
 *    minutes.
 *
 *        Version:  1.0
 *        Created:  08/18/2017 19:21:19
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
 *         Name:  addMinutesInFile
 *  Description:  Totals the minutes stored in files.
 * =============================================================================
 */
int	addMinutesInFile(int flag)
{
	char 	*fileString;
	int		fd;
	char	**arrayOfNumericalValues;
	int		minutesWorked = 0;

	if (flag == 1) {
		fd = open("../doc/dailyMinutesWorkedSchool.txt", O_RDONLY);
	}
	else if (flag == 2) {
		fd = open("../doc/dailyMinutesWorkedHouse.txt", O_RDONLY);
	}
	else if (flag == 3) {
		fd = open("../doc/weeklyMinutesWorkedSchool.txt", O_RDONLY);
	}
	else {
		fd = open("../doc/weeklyMinutesWorkedHouse.txt", O_RDONLY);
	}
	while (get_next_line(fd, &fileString) > 0) {
	}
	arrayOfNumericalValues = ft_strsplit((char const *)fileString, ' ');
	while (*arrayOfNumericalValues) {
		minutesWorked += atoi(*arrayOfNumericalValues);
		arrayOfNumericalValues++;
	}
	close(fd);
	return (minutesWorked);
}		/* -----  end of function addMinutesInFile  ----- */
