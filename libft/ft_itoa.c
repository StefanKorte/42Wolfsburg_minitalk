/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 01:19:32 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 15:57:11 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
** ft_itoa Parameters:
** #1. the integer to convert.
** Return value The string representing the integer. NULL if the
** allocation fails.
** External functs. malloc
** Description: Allocates (with malloc(3)) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
*/

static int	ft_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits ++;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = ft_digits(n);
	str = (char *)malloc (digits * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n > 0)
		n = -n;
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[digits - 1] = - (n % 10) + '0';
		digits--;
		n = n / 10;
	}
	return (str);
}
