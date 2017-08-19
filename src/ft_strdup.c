/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:17:39 by kmaitski          #+#    #+#             */
/*   Updated: 2017/08/18 17:58:21 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strdup
 *  Description:  Returns a pointer to a newly allocated string which is a
 *  			  duplicate of the string s.
 * =============================================================================
 */
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	return (str);
}		/* -----  end of function ft_strdup  ----- */
