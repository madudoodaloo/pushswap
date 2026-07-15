/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 18:51:59 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/14 18:51:59 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_skip(int c, char *skip)
{
	int i;

	i = 0;
	while (skip[i])
	{
		if (c == skip[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_counter(char const *str, char *skip)
{
	int	i;
	int	word;

	i = -1;
	word = 0;
	while (str[++i])
	{
		if (!ft_skip(str[i], skip) && (ft_skip(str[i + 1], skip) || str[i + 1] == '\0'))
			word++;
	}
	return (word);
}

char	**ft_split_strs(char const *str, char *skip)
{
	char	**split;
	int		i;
	int		start;
	int		size;

	split = (char **)malloc(sizeof(char *) * (ft_counter(str, skip) + 1));
	if (!split)
		return (NULL);
	i = 0;
	start = 0;
	while (str[start])
	{
		while (str[start] && ft_skip(str[start], skip))
			start++;
		if (!str[start])
			break;
		size = 0;
		while (str[start + size] && !ft_skip(str[start + size], skip))
			size++;
		split[i++] = ft_substr(str, start, size);
		start += size;
	}
	split[i] = NULL;
	return (split);
}