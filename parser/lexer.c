/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:41:21 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/31 14:41:21 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// iterates through a given string, 
// -1, if it's "" or if contains only whitespaces,
// 0, if it has content to be parsed.

static int	ft_strhascontent(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (-1);
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			break ;
	}
	if (str[i] == '\0')
		return (-1);
	return (0);
}


char *join_and_free(char *str1, char *str2)
{
	char *temp;

	temp = NULL;
	if (str1 && str2)
		temp = ft_strjoin(str1, str2);
	if (str1)
		free(str1);
	return (temp);
}

// checks for null string arguments "", triggering error upon occurence.
// simply converts the full input into a processable array of strs, 
// to be later on parsed, allocating memory for it
char	**lexer(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;
	char	**cmdline;

	i = 0;
	while (++i < ac)
		if (ft_strhascontent(av[i]) < 0)
			return (NULL);
	i = 0;
	str = ft_strdup("");
	while (str && ++i < ac)
	{
		temp = join_and_free(str, av[i]);
		str = join_and_free(temp, " ");
	}
	if (!str)
		return (NULL);
	cmdline = ft_split_strs(str, WHITESPACES);
	free(str);
	return (cmdline);
}
