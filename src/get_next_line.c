/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:40:25 by kmaitski          #+#    #+#             */
/*   Updated: 2017/08/18 17:54:05 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

static void	intialize_line(int newline_loc, int len, char **store, char **line)
{
	char	*tmp;

	tmp = *store;
	if (newline_loc > 0)
	{
		*line = ft_strsub(*store, 0, newline_loc);
		newline_loc++;
		*store = ft_strsub(*store, newline_loc, len - newline_loc);
	}
	else if (newline_loc == 0)
	{
		*store = ft_strsub(*store, 1, len - 1);
		*line = ft_strnew(1);
	}
	else
	{
		*line = ft_strsub(*store, 0, len);
		*store = NULL;
	}
	free(tmp);
}

static int	find_newline(char *store)
{
	int	newline_location;

	newline_location = 0;
	while (store[newline_location])
	{
		if (store[newline_location] == '\n')
		{
			return (newline_location);
		}
		newline_location++;
	}		
	return (-1);
}

void		read_into_store(int fd, char **store, int *store_bytes)
{
	char	*buffer;
	int		read_bytes;
	char	*tmp;

	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	read_bytes = read(fd, buffer, BUFF_SIZE);
	*store_bytes = read_bytes;
	buffer[read_bytes] = '\0';
	if (!*store)
	{
		*store = ft_strdup(buffer);
		tmp = *store;
	}
	else if (store_bytes)
	{
		tmp = *store;
		*store = ft_strjoin(*store, buffer);
		free(tmp);
	}
	free(buffer);
}

int			get_next_line(int fd, char **line)
{
	static char	*store = NULL;
	int			newline_location;
	int			length;
	int			store_bytes;

	store_bytes = 1;
	if (fd < 0 || !line)
		return (-1);
	while (store_bytes > 0)
	{
		read_into_store(fd, &store, &store_bytes);
	}
	if (store_bytes == -1)
	{
		return (-1);
	}
	if (*store)
	{
		length = ft_strlen(store);
		newline_location = find_newline(store);
		intialize_line(newline_location, length, &store, line);
		return (1);
	}
	return (0);
}
