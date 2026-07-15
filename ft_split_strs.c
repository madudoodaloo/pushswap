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

#include "push_swap.h"

int	ft_skip(int c, char *skip)
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
	start = -1;
	while (str[++start])
	{
		size = 0;
		while (!ft_skip(str[start + size], skip) && str[start + size] != '\0')
			size++;
		if ((ft_skip(str[start + size], skip) && size > 0) || str[start + size] == '\0')
		{
			split[i++] = ft_substr(str, start, size);
			if (str[start + size] == '\0')
				break ;
			start += size;
		}
	}
	split[i] = NULL;
	return (split);
}