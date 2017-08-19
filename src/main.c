/*
 * =============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  The second iteration of my timer project that keeps track of
 *    				my hours worked. The plan for this version is to keep track
 *    				of the total hours worked.  At the end of termination it
 *    				save the hours worked to a file and then read that file upon
 *    				opening.  
 *
 *    				I want to be able to differniate the work that I do around
 *    				the house and at school.  To do this I will use the fgets
 *    				function for input into my function. I will enter a code with
 *    				the first character being the key to differniate the input.
 *    				'S' or 's' is the key character for schoolwork; 'H' or 'h'
 *    				is the key character for house work; 'N' or 'n' is the key
 *    				character for new (day, month, year); 'Q' or 'q' is the key
 *    				character for help; and 'T' or 't' is the key character to
 *    				print the total.
 *
 *    				I wanted to check the time and date and compare time
 *    				stamps.  This would have allowed for daily totals, weekly
 *    				totals, monthly totals, and yearly totals.  But this proved
 *    				to be too much for this version but it would be interesting
 *    				feature to implement in the future.
 *
 *    				Instead I am going to manually do this with the leading N
 *    				character.  If I type "ND" it will reset that day and append
 *    				the previous day's result to the correct file.
 *
 *    				Lastly the previous version was running in an infinte loop
 *    				so to cut down on resources I want to be able to pass the
 *    				arguemnts in the command line that will print or accept data
 *    				that I request.
 *
 *
 *        Version:  2.0
 *        Created:  08/07/2017 14:32:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Maitski (KM), kevin.maitski@gmail.com
 *   Organization:  42
 *
 * =============================================================================
 */

#include "timer.h"

/******************************************************
**               funtion prototypes                 ***
*******************************************************/
static void seperateCode(char *code, FILE *dailyMinutesWorkedHouse, FILE *dailyMinutesWorkedSchool);
static void displayTotals(char *code);
static void fileSystem(char *code);

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  main
 *  Description:  This main will recieve the code and pass it along to
 *  			  seperateCode.  If there is more than one argument or no
 *  			  argument at all it will print out an error message and a way
 *  			  to fix the input.
 * =============================================================================
 */
int	main(int argc, char **argv)
{
	FILE	*dailyMinutesWorkedSchool = fopen("../doc/dailyMinutesWorkedSchool.txt", "a");
	FILE	*dailyMinutesWorkedHouse = fopen("../doc/dailyMinutesWorkedHouse.txt", "a");

	if (argc == 2) {
		seperateCode(argv[1], dailyMinutesWorkedHouse, dailyMinutesWorkedSchool);
	}
	else {
		printf("timer takes one (and only one argument).  Please try again.\nFor help run the program again with 'Q' as your argument.");
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  seperateCode
 *  Description:  This first step calls the respective function based off of the
 *  			  key character.
 * =============================================================================
 */
static void	seperateCode(char *code, FILE *dailyMinutesWorkedHouse, FILE *dailyMinutesWorkedSchool)
{
	char	keyCharacter = code[0];

	if (keyCharacter == 'S' || keyCharacter == 's') {
		fprintf(dailyMinutesWorkedSchool, "%s ", ++code);
	}
	else if (keyCharacter == 'H' || keyCharacter == 'h') {
		fprintf(dailyMinutesWorkedHouse, "%s ", ++code);
	}
	 else if (keyCharacter == 'N' || keyCharacter == 'n') {
		fileSystem(++code);
	}
/* 	else if (keyCharacter == 'Q' || keyCharacter == 'q') {
		displayHelpMessage();
	}*/
	else if (keyCharacter == 'T' || keyCharacter == 't') {
		++code;
		fclose(dailyMinutesWorkedHouse);
		fclose(dailyMinutesWorkedSchool);
		displayTotals(code);
	}

	else {
			printf("Invalid key character code.  For help with the key characters run the program again with 'Q' as your argument.");
	}
}		/* -----  end of function seperateCode  ----- */


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  displayTotals
 *  Description:  Displays the total time worked
 * =============================================================================
 */
static void	displayTotals(char *code)
{
	int	minutesWorkedSchool;
	int	minutesWorkedHouse;

	if (*code == 'D' || *code == 'd') {
		minutesWorkedSchool = addMinutesInFile(1);
		minutesWorkedHouse = addMinutesInFile(2);
		printf("You've worked %d hour(s) and %d minute(s) on school and %d hour(s) and %d minute(s) on house work today", minutesWorkedSchool / 60, minutesWorkedSchool % 60, minutesWorkedHouse / 60, minutesWorkedHouse % 60);
	}
	if (*code == 'W' || *code == 'w') {
		minutesWorkedSchool = addMinutesInFile(1) + addMinutesInFile(3);
		minutesWorkedHouse = addMinutesInFile(2) + addMinutesInFile(4);
		printf("You've worked %d hour(s) and %d minute(s) on school and %d hour(s) and %d minute(s) on house work this week", minutesWorkedSchool / 60, minutesWorkedSchool % 60, minutesWorkedHouse / 60, minutesWorkedHouse % 60);
	}
}		/* -----  end of function displayTotals  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  fileSystem
 *  Description:  Based on the code given appends data from one file to another.
 *
 *  			  Daily appends to weekly which appends to monthly which appends
 *  			  to yearly.
 * =============================================================================
 */
static void	fileSystem(char *code)
{
	char	*dataStr;
	int		fdDaily;
	int 	fdWeekly;

	if (*code == 'd' || *code == 'D') {
		fdDaily = open("../doc/dailyMinutesWorkedSchool.txt", O_RDONLY);
		fdWeekly = open("../doc/weeklyMinutesWorkedSchool.txt", O_WRONLY | O_APPEND);
		while (get_next_line(fdDaily, &dataStr) > 0) {
		}
		write(fdWeekly, dataStr, ft_strlen(dataStr));
		close(fdDaily);
		close(fdWeekly);
		free(dataStr);
		fdDaily = open("../doc/dailyMinutesWorkedHouse.txt", O_RDONLY);
		fdWeekly = open("../doc/weeklyMinutesWorkedHouse.txt", O_WRONLY | O_APPEND);
		while (get_next_line(fdDaily, &dataStr) > 0) {
		}
		write(fdWeekly, dataStr, ft_strlen(dataStr));
		close(fdDaily);
		close(fdWeekly);
		free(dataStr);
		fdDaily = open("../doc/dailyMinutesWorkedHouse.txt", O_RDONLY | O_WRONLY | O_TRUNC);
		fdWeekly = open("../doc/dailyMinutesWorkedSchool.txt", O_RDONLY | O_WRONLY | O_TRUNC);
		close(fdDaily);
		close(fdWeekly);
	}
}		/* -----  end of function fileSystem  ----- */
