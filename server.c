/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorte <skorte@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:20:54 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/01/22 08:50:42 by skorte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

/*
** A global variable is used to reset the server when either the end of
** received character is reached or a byte was transferred incompletely.
** If it is set to 1, then the next received signal will purge everything
** that was received since the last complete character.
*/

static unsigned char	g_reset = 1;

static void	ft_reset(unsigned char *c, int *i, pid_t *client_pid)
{
	if (g_reset == 1)
	{
		*c = 0;
		*i = 0;
		*client_pid = 0;
		g_reset = 0;
	}
	return ;
}

/*
** action runs whenever a signal SIGUSR1/2 is caught.
**
** If the PID of the sending client is not the one from the last signal,
** the global character reset flag is set to 1, to prevent interference
** from multiple clients.
**
** Then, if necessary, the char, the bit number i and the client PID
** are reset to 0 by ft_reset.
**
** The client PID is set to be able to reply to the client.
**
** The last bit of the character will be compared to SIGUSR2 (bit = 1).
**
** If the last (7th) bit of the ASCII character is not reached,
** a bit shift by one is done and SIGUSR2 sent to the client.
**
** If the last bit is reached, SIGUSR1 is sent to the client
** to acknowledge complete reception.
** Then, the character is written, the reset flag set.
** SIGUSR1 is sent again to indicate readiness for reception
** of the next character.
*/

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	c;
	static pid_t			client_pid;

	(void)context;
	if (client_pid != info->si_pid)
		g_reset = 1;
	ft_reset(&c, &i, &client_pid);
	client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 7)
	{
		g_reset = 1;
		usleep(50);
		kill(client_pid, SIGUSR1);
		write(1, &c, 1);
		usleep(50);
		kill(client_pid, SIGUSR1);
		return ;
	}
	c <<= 1;
	usleep(50);
	kill(client_pid, SIGUSR2);
	return ;
}

/*
** ft_sig_init sets up the signal set and sigaction for the program.
** Only SIGUSR1/2 and terminating signals are not blocked.
*/

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
** The server first reports its process ID, 
** initializes signal actions, then waits for signals.
**
** When no signal is received for more than 1 ms,
** the global variable g_reset is triggered to 1
** to reset the received character.
*/

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_sig_init();
	while (1)
	{
		if (!usleep(1000))
			g_reset = 1;
	}
	return (0);
}
