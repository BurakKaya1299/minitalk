/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:04 by burkaya           #+#    #+#             */
/*   Updated: 2023/10/26 12:24:02 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static char	*xtoa(unsigned long nbr)
{
	char	*str;
	int		len;

	len = get_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (nbr > 0)
	{
		if (((nbr % 16) >= 0) && ((nbr % 16) <= 9))
			str[len--] = nbr % 16 + '0';
		else
			str[len--] = nbr % 16 + 87;
		nbr /= 16;
	}
	return (str);
}

void	ft_write_address(unsigned long nb, int *i)
{
	char	*add;

	add = xtoa(nb);
	ft_putchar('0', i);
	ft_putchar('x', i);
	if (nb == 0)
		ft_putchar('0', i);
	ft_putstr(add, i);
	free(add);
}
