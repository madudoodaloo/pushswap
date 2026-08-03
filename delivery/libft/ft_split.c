/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 00:16:26 by masilva-          #+#    #+#             */
/*   Updated: 2026/04/21 00:16:26 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_countwords(const char *str, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 0;
	while (str && str[i])
	{
		if (str[i] != c && flag == 0)
		{
			words++;
			flag = 1;
		}
		else if (str[i] == c)
			flag = 0;
		i++;
	}
	return (words);
}

static char	*ft_partialstr(const char *s, int start, int bytes)
{
	int		i;
	char	*str;

	str = ft_calloc(bytes + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < bytes)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

static char	**ft_safe_return(char **split, int x)
{
	int	i;

	i = 0;
	while (i < x)
		free(split[i++]);
	free(split);
	return (NULL);
}

static char	**splitter(char const *s, char c, char **split, int words)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	while (x < words)
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (!j)
			break ;
		split[x] = ft_partialstr(s, i, j);
		if (!split[x])
			return (ft_safe_return(split, x));
		i += j;
		x++;
	}
	split[words] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	words = ft_countwords(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	if (splitter(s, c, split, words) == NULL)
		return (NULL);
	return (split);
}

/* int main()
{
	int i;
	char **split;
	split = ft_split("teste olaaaa como estas?", 32);
	
	if (split)
	{
		for (i = 0; split[i]; i++)
		{
			printf("split[%d] %p -> %s\n", i, split[i], split[i]);
			free(split[i]);
		}
		if (split[i] == NULL)
			printf("split[%d] %p -> NULL\n", i, split[i]);
	}
	else if (!split)
		printf("returned NULL");
	free(split);
}
 */