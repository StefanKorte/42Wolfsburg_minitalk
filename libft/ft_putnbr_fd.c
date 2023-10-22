/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:22:23 by skorte            #+#    #+#             */
/*   Updated: 2021/08/21 16:00:25 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** Outputs the integer ’n’ to the given file descriptor.
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	*num;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		num = ft_itoa(n);
		write(fd, num, ft_strlen(num));
		free (num);
	}
}
