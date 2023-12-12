/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:43:56 by burkaya           #+#    #+#             */
/*   Updated: 2023/11/27 11:56:23 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int signum)
{
	static unsigned char	result;
	static int				i;
	int						nb;

	if (signum == SIGUSR1)
		nb = 1;
	else
		nb = 0;
	i++;
	result = (result << 1) + nb;
	if (i == 7)
	{
		write(1, &result, 1);
		result = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause();
}
