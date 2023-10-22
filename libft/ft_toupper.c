/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:25:54 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:04:08 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The value returned is that of the converted letter, or c if the
** conversion was not possible.
*/

int	ft_toupper(int c)
{
	c = (unsigned char)c;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
