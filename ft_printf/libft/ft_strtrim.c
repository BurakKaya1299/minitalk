/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:27:38 by burkaya           #+#    #+#             */
/*   Updated: 2023/10/14 16:27:40 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtn;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (is_in_set(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		rtn = ft_strdup("");
		if (!rtn)
			return (NULL);
		else
			return (rtn);
	}
	while (is_in_set(s1[end - 1], set) == 0)
		end--;
	rtn = ft_substr(s1, start, end - start);
	return (rtn);
}
