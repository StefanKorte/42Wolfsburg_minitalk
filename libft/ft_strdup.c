/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:49:30 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:01:17 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

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

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		size;
	int		i;

	if (s == NULL)
		return (NULL);
	size = (int)ft_strlen(s);
	dst = malloc(size + 1);
	if (dst == NULL)
	{
		errno = ENOMEM;
		return (dst);
	}
	i = 0;
	while (i <= size)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}
