/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 22:37:59 by masilva-          #+#    #+#             */
/*   Updated: 2026/04/20 22:37:59 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* checks if char c is within set given */
static int	ft_occ(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		l_byte;
	int		i;
	int		j;
	char	*trim;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_occ(s1[i], set))
		i++;
	l_byte = ft_strlen(s1);
	while (l_byte > i && ft_occ(s1[l_byte - 1], set))
		l_byte--;
	trim = ft_calloc(l_byte - i + 1, sizeof(char));
	if (!trim)
		return (NULL);
	j = 0;
	while (s1[i] && i < l_byte)
		trim[j++] = s1[i++];
	return (trim);
}
