/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 00:42:03 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:02:00 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** This function appends the null-terminated string src to the
** string dest, copying at most size-strlen(dest)-1 bytes from src, and
** adds a terminating null byte to the result, unless size is less
** than strlen(dest).  The caller must handle the
** possibility of data loss if size is too small.  The function
** returns the length of the string strlcat() tried to create; if
** the return value is greater than or equal to size, data loss
** occurred.  If data loss matters, the caller must either check the
** arguments before the call, or test the function return value.
** strlcat() is not present in glibc and is not standardized by
** POSIX, but is available on Linux via the libbsd library.
**
** The strlcat function appends the NUL-terminated string src to the end of dst.
** It will append at most size - len(dst) - 1 bytes, NUL-terminating the result.
** Strlcat() returns the total length of the string it tried to create.
** That means the initial length of dst plus the length of src.
** Note, however, that if strlcat() traverses size characters without finding
** a NUL, the length of the string is considered to be size and the destination
** string will not be NUL-terminated (since there was no space for the NUL).
** This keeps strlcat() from running off the end of a string.
*/

static void	ft_set_size(size_t *size, size_t *total_size)
{
	if (*size <= *total_size)
	{
		*total_size = *size;
		*size = 0;
	}
	else
		*size -= (*total_size + 1);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	total_size;
	char	*dest_ptr;

	dest_ptr = dest;
	total_size = 0;
	while (*dest_ptr != '\0' && total_size < size)
	{
		dest_ptr++;
		total_size++;
	}
	ft_set_size(&size, &total_size);
	while (*src != '\0')
	{
		if (size > 0)
		{
			*dest_ptr = *src;
			dest_ptr++;
			*dest_ptr = '\0';
			size--;
		}
		src++;
		total_size++;
	}
	return (total_size);
}
