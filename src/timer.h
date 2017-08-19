/*
 * =============================================================================
 *
 *       Filename:  timer.h
 *
 *    Description:  A header file for the timer project.
 *
 *        Version:  1.0
 *        Created:  08/07/2017 15:04:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Maitski (KM), kevin.maitski@gmail.com
 *   Organization:  42
 *
 * =============================================================================
 */

#ifndef TIMER_H
# define TIMER_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 2000
//# include <string.h>

int		main(int argc, char **argv);
void	schoolWorkTimer(char *code);
int		addMinutesInFile(int flag);

/* 
 *	get_next_line files
 */

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
