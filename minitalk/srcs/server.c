/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:48:53 by dwarlock          #+#    #+#             */
/*   Updated: 2022/03/08 20:13:31 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receipt_confirmation(pid_t *client_pid)
{
	kill(*client_pid, SIGUSR1);
	*client_pid = 0;
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i;
	static pid_t			client_pid;
	static unsigned char	c;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		i = 0;
		c = 0;
	}
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			receipt_confirmation(&client_pid);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
