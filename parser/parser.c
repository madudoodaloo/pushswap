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
// -1, if str is outside int range
// -2, if str contains invalid int characters
static int ft_checkint(char *str)
{
	int	i;
	long int temp;

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
// -1, if args are outside int range
// -2, if no args list was provided
// -3, if invalid option usage is detected
static int	ft_checksyntax(char **cmdl)
{
	int i = 0;
	int j = 0;

    if (!cmdl || !cmdl[0])
        return (-2);
    while (cmdl[i])
    {
		if (j >= 0)
        	j = ft_checkint(cmdl[i]);
        if (j == -1)
            return (-1);
        if (j == -2)
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
static bool ft_checkdups(char **cmdl)
{
	bool dup;
	long int curr;
	long int temp;
	int	i;
	int j;

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
// -1: provided input is not within int range
// -2: missing ints list to sort
// -3: invalid int format or flag input
// -4: has dups
int	parser(char **cmdl, t_stack **a, t_bench *bench)
{
	int ret;

	if (!cmdl || !cmdl[0])
	{
		free_matrix(cmdl);
		return (-2);
	}
	ret = ft_checksyntax(cmdl);
	if (ret < 0 || ft_checkdups(cmdl))
	{
		free_matrix(cmdl);
		if (!ret)
			return (-4);
		return (ret);
	}
	tokenizer(cmdl, a, bench);
	free_matrix(cmdl);
	return (0);
}

// simply converts the full input into a processable array of strs, to be later on parsed, allocating memory for it
char	**lexer(int ac, char **av)
{
	int i; //skip av[0]
	char *str;
	char *temp;
	char **cmdline;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (++i < ac)
	{
		temp = ft_strjoin(str, av[i]);
		free(str);
		str = ft_strjoin(temp, " ");
		free(temp);
	}
	cmdline = ft_split_strs(str, WHITESPACES); // needs free()
	free(str);
	return (cmdline);
}
