/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 01:18:59 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 15:55:00 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks for an alphabetic character; in the standard "C"
** locale, it is equivalent to (isupper(c) || islower(c)).
*/

int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
