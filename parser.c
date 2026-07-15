/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 03:48:35 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/15 03:48:35 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// flag meanings
// 'i' = integers only, meaning a string containing a single sign and only digits
// 'c' = characters only, meaning a string with letters only and '-' char
// 0: contains only expected type
// -1: invalid characters

int ft_checkchars(char *str, int type)
{
	int	i;

	i = 0;
	if (type == 'i')
	{
		if (*str == '-' || *str == '+')
			i++;
		while (str[i])
			if (!ft_isdigit(str[i++]))
				return (-1);
	}
//	else if (type == 'c')
//	{
//		if (ft_strncmp(str, "--", 2) == 0)
//			i += 2;
//		while (str[i])
//			if (!ft_islower(str[i++]))
//				return (-1);
//	}
	return (0);
}

int	ft_checksyntax(char **cmdl)
{
	int i = 0;
	int j = 0;

	while (cmdl[i])
	{
		if (ft_checkchars(cmdl[i], 'i') < 0)
			break ;
		else if (!ft_checkrange(cmdl[i]))
			return (-1);
		i++;
	}
	if (i == 0)
		return (-2);
	j = -1;
	while (++j < 3 && cmdl[i + j])
		if (ft_getoptions(cmdl[i + j], 'p') < 0)
			return (-3);
	return (0);
}

bool ft_checkdups(char **cmdl)
{
	bool dup;

	dup = 0;
	while (cmdl && cmdl[++i] && !dup)
	{
		j = i;
		while (cmdl[++j])
			if (ft_strcmp(cmdl[i], cmdl[j]) == 0)
				dup == 1;
		i++;
	}
	return (dup);
}

// error list parser
// 0: success
// -1: provided input is not within int range
// -2: missing ints list to sort
// -3: invalid int format or flag input
// -4: has dups
int	parser(char **cmdl, t_stack *a, t_bench *bench)
{
	int error;

	error = ft_checksyntax(cmdl);
	if (error < 0 || ft_checkdups(cmdl))
	{
		free_matrix(cmdl);
		if (!error)
			return (-4)
		return (error);
	}
	tokenizer(cmdl, a, bench);
	free_matrix(cmdl);
	return (0);
}

// sö pode receber uma flag de selector no mäximo, e bench opcional.
// 1o, lista formatada de ints da stack a, depois flags.
char	**lexer(int ac, char **av)
{
	int i = 0; //skip av[0]
	char *str;
	char **cmdline;

	cmdline = NULL;
	str = NULL;
	while (++i < ac)
	{
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
	}
	ft_printf("str is: %s\n", str);
	if (!str)
		return (NULL);
	cmdline = ft_split_strs(str, WHITESPACES); // needs free()
	free(str);
	return (cmdline);
}
