/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:48:46 by dwarlock          #+#    #+#             */
/*   Updated: 2022/03/08 20:13:05 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	success_msg(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Data was received by server\n", 1);
		exit(0);
	}
}

static void	end_of_msg(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		usleep(100);
	}
}

static void	sig_emitter_loop(int pid, int c, int i)
{
	while (i--)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR2))
			{
				ft_putstr_fd("Bad pid\n", 2);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1))
			{
				ft_putstr_fd("Bad pid\n", 2);
				exit(0);
			}
		}
		usleep(100);
		usleep(100);
	}
}

static void	sig_emitter(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		sig_emitter_loop(pid, c, i);
	}
	end_of_msg(pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		ft_putstr_fd("Usage: ./client [server_pid] [msg_to_send]\n", 2);
	else
	{
		signal(SIGUSR1, success_msg);
		sig_emitter(ft_atoi(argv[1]), argv[2]);
		while (1)
			pause();
	}
	return (0);
}
