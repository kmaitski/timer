/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:36:13 by kmaitski          #+#    #+#             */
/*   Updated: 2017/08/08 16:03:59 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

static int	overflow(const char *string_ptr)
{
	int		length;
	int 	string_compare_result;
	size_t	i;

	length = 0;
	string_compare_result = 0;
	i = 0;
	while (string_ptr[i])
	{
		if (ft_isdigit(string_ptr[i]))
			length++;
		i++;
	}
	if (length > 18)
	{
		string_compare_result = ft_strcmp(string_ptr, "9223372036854775807");
		if (string_compare_result >= 0)
			return (1);
	}
	return (0);
}

/** 
 ** ===  FUNCTION  =============================================================
 **         Name:  ft_atoi
 **  Description:  Takes a string and iterates through until finding a number
 				  and then returns an int of the same value as the string
				  number.
 ** ============================================================================
 **/
int			ft_atoi(const char *string_ptr)
{
	int	result;
	int				negative_flag;
	int				too_big_flag;

	result = 0;
	negative_flag = 1;
	while (*string_ptr > 0 && *string_ptr < 33 && *string_ptr != '\e')
		string_ptr++;
	if (*string_ptr == '-')
		negative_flag = -1;
	if (*string_ptr == '-' || *string_ptr == '+')
		string_ptr++;
	too_big_flag = overflow(string_ptr);
	if (too_big_flag && negative_flag == 1)
		return (-1);
	if (too_big_flag  && negative_flag == -1)
		return (0);
	while (*string_ptr >= '0' && *string_ptr <= '9')
		result = result * 10 + *string_ptr++ - '0';
	if (result == 2147483648 && negative_flag == -1)
		return (-2147483648);
	return (result * negative_flag);
}
