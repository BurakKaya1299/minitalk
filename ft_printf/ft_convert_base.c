/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:48:39 by burkaya           #+#    #+#             */
/*   Updated: 2023/10/26 12:23:55 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned int nbr)
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

static char	*ft_check_base(char type)
{
	if (type == 'x')
		return (ft_strdup("0123456789abcdef"));
	else
		return (ft_strdup("0123456789ABCDEF"));
}

static void	ft_check(unsigned int nbr, int *i)
{
	if (nbr == 0)
		ft_putstr("0", i);
}

void	ft_convert_base(unsigned int nbr, char type, int *i)
{
	char	*str;
	int		len;
	char	*base;

	if (nbr == 0)
		ft_check(nbr, i);
	base = ft_check_base(type);
	len = get_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	str[len--] = '\0';
	while (nbr > 0)
	{
		str[len--] = base[nbr % 16];
		nbr /= 16;
	}
	ft_putstr(str, i);
	free(str);
	free(base);
}
