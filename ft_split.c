/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:25:35 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/11/15 20:26:29 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_counter(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_getstr(const char *s, int word_pos, int word_size)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(word_size + 1);
	while (i < word_size)
	{
		str[i] = s[word_pos + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	is_split(const char *s, char c, char **str, size_t *filled)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j])
		{
			len = 0;
			while (s[j + len] && s[j + len] != c)
				len++;
			str[i] = ft_getstr(s, j, len);
			if (!str[i])
				return (0);
			(*filled)++;
			i++;
			j += len;
		}
	}
	str[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	filled;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!str)
		return (NULL);
	filled = 0;
	if (!is_split(s, c, str, &filled))
	{
		while (filled > 0)
			free(str[--filled]);
		free(str);
		return (NULL);
	}
	return (str);
}
