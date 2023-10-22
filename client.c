/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:33:05 by skorte            #+#    #+#             */
/*   Updated: 2022/01/22 08:50:31 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/*
** The global variable g_success gets set to 1 when the server signals
** that it has received a complete character (7th bit for ASCII).
** This is done with a SIGUSR1.
**
** For each of the other 6 bits, the acknowledgement from the
** server is SIGUSR2, which sets g_success to 0.
*/

static int	g_success;

static void	action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	info->si_pid;
	g_success = (sig == SIGUSR1);
}

static void	ft_send_char(int pid, char c)
{
	int		i;
	{
		i = 7;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			if (!usleep(1000000))
			{
				g_success = 0;
				return ;
			}
		}
	}
}

static void	ft_output(int send_success, int send_attempts)
{
	ft_putstr_fd("\r                                        ", 1);
	ft_putstr_fd("                                        \r", 1);
	ft_putstr_fd("Sent bytes: ", 1);
	ft_putnbr_fd(send_success, 1);
	ft_putstr_fd("  (Re-sent bytes: ", 1);
	ft_putnbr_fd(send_attempts - send_success, 1);
	ft_putstr_fd(")", 1);
	if (send_attempts > 10 && send_success == 1)
	{
		ft_putstr_fd("\r                                           ", 1);
		ft_putstr_fd("\rServer not responding, correct PID?\n", 1);
		exit (1);
	}
	return ;
}

static void	ft_sig_init(void)
{	
	struct sigaction	my_sigaction;
	sigset_t			my_sigset;

	sigemptyset(&my_sigset);
	sigaddset(&my_sigset, SIGUSR1);
	sigaddset(&my_sigset, SIGUSR2);
	ft_memset(&my_sigaction, 0, sizeof(struct sigaction));
	my_sigaction.sa_sigaction = action;
	my_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &my_sigaction, 0);
	sigaction(SIGUSR2, &my_sigaction, 0);
}

/*
**
*/

int	main(int argc, char **argv)
{
	int		send_success;
	int		send_attempts;

	g_success = 0;
	send_success = 0;
	send_attempts = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("Usage: ./client SERVER_PID STRING. Try again :-)\n", 1);
		return (1);
	}
	ft_sig_init();
	while (*argv[2] && ++send_success)
	{
		while (!g_success && ++send_attempts)
		{
			ft_send_char(ft_atoi(argv[1]), *argv[2]);
			ft_output(send_success, send_attempts);
			usleep(10000);
		}
		g_success = 0;
		argv[2]++;
	}
	ft_putstr_fd("\nSending completed!\n", 1);
	return (0);
}

/*
** Test: time ./client $(pgrep -x server) "$(<test)"
*/
