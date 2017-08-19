/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:07:22 by kmaitski          #+#    #+#             */
/*   Updated: 2017/08/18 18:22:04 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strjoin
 *  Description:  Allocates and returns a “fresh” string ending with ’\0’,
 *  			  result of the concatenation of s1 and s2. If the allocation
 *  			  fails the function returns NULL.
 * =====================================================================================
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*fresh;
	int				i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(fresh = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		fresh[i] = s1[i];
	while (s2[j])
		fresh[i++] = s2[j++];
	fresh[i] = '\0';
	return (fresh);
}		/* -----  end of function ft_strjoin  ----- */
