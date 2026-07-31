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

#include "../push_swap.h"

// 	ft_checkint returns:
//  0, if str is a valid int
// -1, if str is outside int range or is an invalid int ("-" or "+")
// -2, if str contains invalid int characters

static int	ft_checkint(char *str)
{
	int			i;
	long int	temp;

	temp = ft_atol(str);
	if (ft_strlen(str) > 11 || temp < INT_MIN || temp > INT_MAX)
		return (-1);
	i = 0;
	if (*str == '-' || *str == '+')
		i++;
	if (!str[i])
		return (-1);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (-2);
	return (0);
}

// 	ft_checksyntax returns:
//  0, if the provided input is valid
// -1, if args are outside int range or a single '-' or '+'
// -2, if no args list was provided
// -3, if invalid option usage is detected

static int	ft_checksyntax(char **cmdl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!cmdl || !cmdl[0])
		return (-2);
	while (cmdl[i])
	{
		if (j == 0)
			j = ft_checkint(cmdl[i]);
		if (j == -1)
			return (-1);
		else if (j == -2)
		{
			if (i == 0)
				return (-2);
			else if (ft_getoptions(cmdl[i], 'p') < 0)
				return (-3);
		}
		i++;
	}
	return (0);
}

// ft_checkdups returns:
// 0, if no dups were found
// 1, if has dups
static bool	ft_checkdups(char **cmdl)
{
	long int	curr;
	long int	temp;
	bool		dup;
	int			i;
	int			j;

	i = 0;
	dup = 0;
	while (cmdl && !dup && cmdl[i] && ft_checkint(cmdl[i]) == 0)
	{
		curr = ft_atol(cmdl[i]);
		j = i;
		while (cmdl[++j] && !dup && ft_checkint(cmdl[j]) == 0)
		{
			temp = ft_atol(cmdl[j]);
			if (curr == temp)
				dup = 1;
		}
		i++;
	}
	return (dup);
}

//  parser returns:
//  0: success
// -1: cmdl is empty or malloc failed to allocate it
// -2: wrong cmdline - invalid int format or flag input
// -3: ints list has dups

int	parser(char **cmdl, t_stack **a, t_bench *bench)
{
	if (!cmdl || !cmdl[0])
		ft_error(-1, a, cmdl);
	if (ft_checksyntax(cmdl) < 0)
		ft_error(-2, a, cmdl);
	if (ft_checkdups(cmdl) == 1)
		ft_error(-3, a, cmdl);
	tokenizer(cmdl, a, bench);
	free_matrix(cmdl);
	return (0);
}

