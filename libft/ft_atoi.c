/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 01:18:40 by skorte           #+#    #+#             */
/*   Updated: 2021/08/21 15:53:09 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The atoi() function converts the initial portion of the string
** pointed to by nptr to int.  The behavior is the same as
** strtol(nptr, NULL, 10) except that atoi() does not detect errors.
** The string may begin with an arbitrary amount of white space
** followed by a single optional '+' or '-' sign.
** The remainder of the string is converted to a long value in the
** obvious manner, stopping at the first character which is not a
** valid digit in the given base.
*/

static const char	*ft_skip(const char *nptr)
{
	while (1)
	{
		if (*nptr == ' ' || *nptr == '\t' || *nptr == '\v')
			nptr++;
		else if (*nptr == '\r' || *nptr == '\n' || *nptr == '\f')
			nptr++;
		else
			break ;
	}
	return (nptr);
}

int	ft_atoi(const char *nptr)
{
	long int	output_int;
	long int	sign;

	sign = 1;
	nptr = ft_skip(nptr);
	if (*nptr == '-')
		sign = -1;
	else if (*nptr == '+')
		sign = 1;
	else
		nptr--;
	nptr++;
	output_int = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{	
		output_int = output_int * 10 + *nptr - '0';
		if (sign * output_int > 2147483647)
			return (-1);
		if (sign * output_int < -2147483648)
			return (0);
		nptr++;
	}
	output_int = sign * output_int;
	return ((int)output_int);
}
