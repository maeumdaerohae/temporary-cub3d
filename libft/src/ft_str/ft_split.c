/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:05:40 by afavier           #+#    #+#             */
/*   Updated: 2024/03/12 19:54:39 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	**ft_split_next(char const *s, char c, char **new);

static char	**free_array(char **tab, size_t max)
{
	size_t	i;

	i = 0;
	while (max > i)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static	int	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static char	*ft_strdupp(const char *s, size_t start, size_t end)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = malloc(sizeof(char) * (end - start + 1));
	if (!tab)
		return (NULL);
	while (end > start)
	{
		tab[i] = s[start];
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!new)
		return (NULL);
	new = ft_split_next(s, c, new);
	return (new);
}

static char	**ft_split_next(char const *s, char c, char **new)
{
	size_t	i;
	size_t	start;
	size_t	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			new[y] = ft_strdupp(s, start, i);
			if (!new[y++])
				return (free_array(new, y));
		}
	}
	new[y] = 0;
	return (new);
}
