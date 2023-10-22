/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:43:47 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 15:54:11 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** The calloc() function shall allocate unused space for an array of
** nelem elements each of whose size in bytes is elsize.  The space
** shall be initialized to all bits 0.
*/

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*dst;

	dst = malloc(nelem * elsize);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, nelem * elsize);
	return (dst);
}
