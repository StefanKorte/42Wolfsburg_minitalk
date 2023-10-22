/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:31:19 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:02:51 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** The strncmp() function compares the first (at most) n bytes
** of the two strings s1 and s2.
** The comparison is done using unsigned characters.
** Returns:
** 0, if the s1 and s2 are equal;
** a negative value if s1 is less than s2;
** a positive value if s1 is greater than s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < (int)n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
