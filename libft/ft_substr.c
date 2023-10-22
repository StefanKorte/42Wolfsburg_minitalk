/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:45:59 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:03:46 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Parameters
** #1. The string from which to create the substring.
** #2. The start index of the substring in the string ’s’.
** #3. The maximum length of the substring.
** Return value: The substring. NULL if the allocation fails.
** External functs. malloc
** Description: Allocates (with malloc(3)) and returns a substring
** from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		size;
	int		i;

	if ((signed long)len < 0)
		return (NULL);
	size = ft_strlen(s) - start;
	if (size > (signed long)len)
		size = len;
	else if (size < 0)
		size = 0;
	dst = malloc(size + 1);
	if (dst == NULL)
		return (dst);
	i = 0;
	while (i < size)
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[size] = 0;
	return (dst);
}
