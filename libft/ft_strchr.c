/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:30:07 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:01:05 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** The strchr() function returns a pointer to the first occurrence
** of the character c in the string s or NULL if the character is not found.
** The terminating null byte is considered part of the string, so that
** if c is specified as '\0', this function returns a pointer to the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	while (s[0] != '\0')
	{
		if (s[0] == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
