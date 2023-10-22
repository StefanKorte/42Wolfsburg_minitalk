/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:26:07 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:03:55 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The value returned is that of the converted letter, or c if the
** conversion was not possible.
*/

int	ft_tolower(int c)
{
	c = (unsigned char)c;
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
