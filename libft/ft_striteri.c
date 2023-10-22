/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:52:26 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:01:29 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the
** string passed as argument, and passing its index
** as first argument. Each character is passed by
** address to f to be modified if necessary
** Parameters:
** #1The string on which to iterate.
** #2. The function to apply to each character.
** Return value: None
** External functs. None
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
