/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 09:39:32 by kmaitski          #+#    #+#             */
/*   Updated: 2017/08/18 18:00:18 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strlen
 *  Description:  Computes the length of the string str up to, but not including
 *  			  the terminating null character.
 * =============================================================================
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}		/* -----  end of function ft_strlen  ----- */
