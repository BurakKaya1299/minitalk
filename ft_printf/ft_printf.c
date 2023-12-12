/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:49:12 by burkaya           #+#    #+#             */
/*   Updated: 2023/10/26 12:22:36 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_spec(char *str, int j, int *i, va_list *ap)
{
	if (str[j + 1] == '%')
		ft_putchar('%', i);
	else if (str[j + 1] == 'c')
		ft_putchar(va_arg(*ap, int), i);
	else if (str[j + 1] == 's')
		ft_putstr(va_arg(*ap, char *), i);
	else if (str[j + 1] == 'd' || str[j + 1] == 'i')
		ft_putnbr(va_arg(*ap, int), i);
	else if (str[j + 1] == 'u')
		ft_putnbr_u(va_arg(*ap, unsigned int), i);
	else if (str[j + 1] == 'x' || str[j + 1] == 'X')
		ft_convert_base(va_arg(*ap, unsigned int), str[j + 1], i);
	else if (str[j + 1] == 'p')
		ft_write_address(va_arg(*ap, unsigned long), i);
	else
		return (0);
	return (1);
}

static void	ft_main(char *str, va_list *ap, int *i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '%')
		{
			if (ft_find_spec(str, j, i, ap) == 1)
				j += 2;
		}
		else
			ft_putchar(str[j++], i);
	}
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, s);
	str = ft_strdup(s);
	ft_main(str, &ap, &i);
	va_end(ap);
	free(str);
	return (i);
}
