/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:27:54 by kmaitski          #+#    #+#             */
/*   Updated: 2017/08/18 18:32:04 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strsub
 *  Description:  Allocates and returns a “fresh” substring from the string
 *  			  given as argument. The substring begins at indexstart and is
 *  			  of size len. If start and len aren’t refering to a valid
 *  			  substring, the behavior is undefined. If the allocation fails,
 *  			  the function returns NULL.
 * =====================================================================================
 */
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}		/* -----  end of function ft_strsub  ----- */
