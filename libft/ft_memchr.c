/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:12:44 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 15:57:40 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h> 
#include "libft.h"

/*
** The memchr() function scans the initial n bytes of the memory area pointed to
** by s for the first instance of c. Both c and the bytes of the memory area
** pointed to by s are interpreted as unsigned char.
** Return Value: The memchr() function returns a pointer to the matching byte
** or NULL if the character does not occur in the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == cc)
			return ((void *)s);
		s++;
		i++;
	}
	return (0);
}
