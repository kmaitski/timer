/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaitski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:54:57 by kmaitski          #+#    #+#             */
/*   Updated: 2017/08/18 18:30:42 by kmaitski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  word_count
 *  Description:  Returns the amount of "words" in the string.
 * =============================================================================
 */
static unsigned int	word_count(char const *s, char c)
{
	int				i;
	unsigned int	j;

	i = -1;
	j = 0;
	while (s[++i])
		if ((s[i] != c && s[i + 1] == c) || (s[i + 1] == '\0' && s[i] != c))
			j++;
	return (j);
}		/* -----  end of function word_count  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  word_length
 *  Description:  Returns the length of a "word". 
 * =============================================================================
 */
static unsigned int	word_length(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}		/* -----  end of function word_length  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  populate_2d
 *  Description:  Intializes and assigns the strings to the 2d array.
 * =============================================================================
 */
static char			**populate_2d(char const *s, char **arr, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	word_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_len = word_length(&s[i], c);
			if (!(arr[j] = ft_strsub(s, i, word_len)))
				return (NULL);
			i += word_len;
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}		/* -----  end of function populate_2d  ----- */

/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  ft_strsplit
 *  Description:  Allocates and returns an array of “fresh” strings obtained by
 *  			  spliting s using the character c as a delimiter. If the
 *  			  allocation fails the function returns NULL. Example :
 *  			  ft_strsplit("*hello*fellow***students*", ’*’) returns the
 *  			  array ["hello","fellow", "students"].
 * =============================================================================
 */
char				**ft_strsplit(char const *s, char c)
{
	unsigned int	words;
	char			**fresh;

	if (!s || !c)
		return (NULL);
	words = word_count(s, c);
	if (!(fresh = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	populate_2d(s, fresh, c);
	return (fresh);
}		/* -----  end of function ft_strsplit  ----- */
