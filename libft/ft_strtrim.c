/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:11:17 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:03:36 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strdup() function returns a pointer to a new string which is
** a duplicate of the string s.  Memory for the new string is
** obtained with malloc(3), and can be freed with free(3).
** On success, the strdup() function returns a pointer to the
** duplicated string.  It returns NULL if insufficient memory was
** available, with errno set to indicate the error.
** The strndup() function is similar, but only copies at most n bytes.
** If s is longer than n, only n bytes are copied,
** and a terminating null byte ('\0') is added. 
*/

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dst;
	size_t	size;
	int		i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size > n)
		size = n;
	dst = malloc(size + 1);
	if (dst == NULL)
	{
		errno = ENOMEM;
		return (dst);
	}
	i = 0;
	while (i < (int)size)
	{
		dst[i] = s[i];
		i++;
	}
	dst[size] = 0;
	return (dst);
}

/*
** Parameters
** #1. The string to be trimmed.
** #2. The reference set of characters to trim.
** Return value: The trimmed string. NULL if the allocation fails.
** External functs. malloc
** Description: Allocates (with malloc(3)) and returns a copy of
** ’s1’ with the characters specified in ’set’ removed
** from the beginning and the end of the string.
*/

static int	ft_totrim(char c, const char *set)
{
	while (set[0] != '\0')
	{
		if (c == set[0])
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	int		len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strndup(s1, ft_strlen(s1) + 1));
	start = 0;
	while (ft_totrim(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_totrim(s1[end], set) && end > start)
		end--;
	len = (int)end - (int)start + 1;
	if (len < 0)
		len = 0;
	return (ft_substr(s1, start, len));
}
