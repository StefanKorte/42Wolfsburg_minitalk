/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 01:28:25 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 15:59:25 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/*
** The memmove() function copies n bytes from memory area src
** to memory area dest. The memory areas may overlap:
** copying takes place as though the bytes in src
** are first copied into a temporary array that
** does not overlap src or dest, and the bytes are then
** copied from the temporary array to dest.
** Return Value: The memmove() function returns a pointer to dest.
*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		while (n--)
			dest[n] = source[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
