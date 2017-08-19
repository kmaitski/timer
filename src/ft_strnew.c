/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:58:48 by kmaitski          #+#    #+#             */
/*   Updated: 2017/08/18 17:57:25 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strnew
 *  Description:  Allocates and returns a “fresh” string ending with ’\0’. Each 
 *  			  character of the string is initialized at ’\0’. If the 
 *  			  allocation fails the function returns NULL.
 * =============================================================================
 */
char	*ft_strnew(size_t size)
{
	char	*fresh;
	size_t	i;

	if (!(fresh = (char *)malloc(size + 1)))
		return (NULL);
	i = -1;
	while (++i <= size)
		fresh[i] = '\0';
	return (fresh);
}	  /* -----  end of function ft_strnew  ----- */

