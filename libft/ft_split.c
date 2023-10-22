/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 00:56:57 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:00:50 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

/*
** ft_split Parameters:
** #1. The string to be split.
** #2. The delimiter character.
Return value: The array of new strings resulting from the split.
NULL if the allocation fails.
External functs. malloc, free
Description: Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.
*/

static void	ft_init(int *i, int *n, int *start, int *len)
{
	*i = 0;
	*n = 0;
	*start = 0;
	*len = 0;
}

static int	ft_str_word_count(char const *s, char c)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	n = 0;
	len = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (len != 0)
				n++;
			len = 0;
		}
		else
			len++;
		i++;
	}
	return (n);
}

static void	ft_str_words(char const *s, char **dest, char c)
{
	int	i;
	int	n;
	int	start;
	int	len;

	ft_init(&i, &n, &start, &len);
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (len != 0)
			{
				dest[n] = ft_substr(s, start, len);
				n++;
			}
			len = 0;
			start = i + 1;
		}
		else
			len++;
		i++;
	}
	dest[n] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		n;

	if (!s)
		return (NULL);
	n = ft_str_word_count(s, c);
	dest = malloc((n + 1) * sizeof(char *));
	if (dest == NULL)
		return (dest);
	ft_str_words(s, dest, c);
	return (dest);
}
