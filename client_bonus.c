/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:43:36 by burkaya           #+#    #+#             */
/*   Updated: 2023/11/27 14:27:12 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char	*str, int own_pid)
{
	int				i;
	unsigned char	c;

	i = 8;
	while (*str)
	{
		c = *str;
		while (i--)
		{
			if ((c >> i & 1))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i = 8;
		str++;
	}
	usleep(100);
	kill(own_pid, SIGUSR2);
}

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("message received\n");
	else
		exit(1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	own_pid;

	if (argc != 3)
	{
		ft_printf("Wrong usage: ./client_bonus.c [PID] [MESSAGE]");
		exit(0);
	}
	own_pid = getpid();
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	send_message(pid, argv[2], own_pid);
	return (0);
}
