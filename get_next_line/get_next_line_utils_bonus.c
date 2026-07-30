/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 04:26:22 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/01 04:26:22 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_linelen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(ft_linelen(line) + ft_linelen(buff) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	if (line)
		free(line);
	while (buff[j])
	{
		new[i++] = buff[j];
		if (buff[j++] == '\n')
			break ;
	}
	new[i] = '\0';
	return (new);
}

int	ft_clean(char *buff)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = 0;
	j = 0;
	while (buff[i])
	{
		if (flag == 1)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			flag = 1;
		buff[i++] = '\0';
	}
	return (flag);
}
