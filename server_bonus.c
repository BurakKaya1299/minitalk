/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:07 by burkaya           #+#    #+#             */
/*   Updated: 2023/11/27 12:32:04 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int signum, siginfo_t *sa, void *content)
{
	static unsigned char	result = 0;
	static int				i = 0;
	int						nb;

	(void)content;
	if (signum == SIGUSR1)
		nb = 1;
	else
		nb = 0;
	i++;
	result = (result << 1) + nb;
	if (i == 8)
	{
		write(1, &result, 1);
		kill(sa->si_pid, SIGUSR1);
		result = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = sighandler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (0);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return (0);
	while (1)
		pause();
}
