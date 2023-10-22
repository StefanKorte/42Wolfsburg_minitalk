/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:30:50 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:03:27 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** The strrchr() function returns a pointer to the last occurrence
** of the character c in the string s.
** The terminating null byte is considered part of the string, so that
** if c is specified as '\0', these functions return a pointer to the terminator.
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = 0;
	while (s[0] != '\0')
	{
		size++;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	s--;
	while (size > 0)
	{
		if (s[0] == c)
			return ((char *)s);
		s--;
		size--;
	}
	return (0);
}
