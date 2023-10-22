/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:28:05 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:02:12 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** The strcpy() function copies the string pointed to by src,
** including the terminating null byte ('\0'), to the buffer pointed
** to by dest.  The strings may not overlap, and the destination
** string dest must be large enough to receive the copy.  Beware of
** buffer overruns!  (See BUGS.)
**
** The strncpy() function is similar, except that at most n bytes of
** src are copied.  Warning: If there is no null byte among the
** first n bytes of src, the string placed in dest will not be null-
** terminated.
** If the length of src is less than n, strncpy() writes additional
** null bytes to dest to ensure that a total of n bytes are written.
** strlcpy() is similar to strncpy(), but it copies at most
** size-1 bytes to dest, always adds a terminating null byte, and
** does not pad the destination with (further) null bytes.  This
** function fixes some of the problems of strcpy() and strncpy(),
** but the caller must still handle the possibility of data loss if
** size is too small.  The return value of the function is the
** length of src, which allows truncation to be easily detected: if
** the return value is greater than or equal to size, truncation
** occurred.  If loss of data matters, the caller must either check
** the arguments before the call, or test the function return value.
** strlcpy() is not present in glibc and is not standardized by
** POSIX, but is available on Linux via the libbsd library.
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!src)
		return (0);
	if (!dest || size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
