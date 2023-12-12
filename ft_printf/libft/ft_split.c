/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:26:30 by burkaya           #+#    #+#             */
/*   Updated: 2023/10/14 16:26:32 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_seperator(char s, char c)
{
	if (c == s)
		return (1);
	if (s == '\0')
		return (1);
	return (0);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] && char_is_seperator(str[i + 1], c) == 1
			&& char_is_seperator(str[i], c) == 0)
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *split, const char *src, char c)
{
	int	i;

	i = 0;
	while (char_is_seperator(src[i], c) == 0)
	{
		split[i] = src[i];
		i++;
	}
	split[i] = '\0';
}

static void	write_split(char **res, const char *str, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (char_is_seperator(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_seperator(str[i + j], c) == 0)
				j++;
			res[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!res[word])
				return ;
			write_word(res[word], str + i, c);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;

	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	write_split(res, s, c);
	return (res);
}
