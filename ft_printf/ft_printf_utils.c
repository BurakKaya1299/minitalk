/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:57:39 by burkaya           #+#    #+#             */
/*   Updated: 2023/10/25 10:56:59 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_putstr(char *str, int *i)
{
	int	j;

	if (!str)
	{
		ft_putstr("(null)", i);
		return ;
	}
	j = 0;
	while (str[j])
	{
		ft_putchar(str[j], i);
		j++;
	}
}

void	ft_putnbr(int nb, int *i)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', i);
		ft_putchar('2', i);
		ft_putnbr(147483648, i);
	}
	else if (nb < 0)
	{
		ft_putchar('-', i);
		nb = -nb;
		ft_putnbr(nb, i);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, i);
		ft_putnbr(nb % 10, i);
	}
	else
	{
		ft_putchar(nb + 48, i);
	}
}

void	ft_putnbr_u(unsigned int nb, int *i)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, i);
		ft_putnbr(nb % 10, i);
	}
	else
	{
		ft_putchar(nb + 48, i);
	}
}
