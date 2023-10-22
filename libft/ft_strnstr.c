/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:16:45 by skorte            #+#    #+#             */
/*   Updated: 2021/08/24 16:03:17 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strnstr() function locates the first occurrence of the null-termi-
** nated string little in the string big, where not more than len characters
** are searched. Characters that appear after a `\0' character are not
** searched.
** If little is an empty string, big is returned; if little occurs nowhere
** in big, NULL is returned; otherwise a pointer to the first character of
** the first occurrence of little is returned.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	length;

	if (!little[0])
		return ((char *)big);
	i = 0;
	length = (int)len;
	while (i < length && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < length)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
