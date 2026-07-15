/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 03:22:37 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/14 03:22:37 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_checkchars(char *str, int type)
{
	int	i;

	i = 0
	if (type == 'i')
	{
		if (*str == '-' || *str == '+')
			i++;
		while (str[i])
			if (!ft_isdigit(str[i++]))
				return (-1);
	}
	else if (type == 'c')
	{
		if (ft_strncmp(str, "--", 2) == 0)
			i += 2;
		while (str[i])
			if (!ft_islower(str[i++]))
				return (-1);
	}
	return (0);
}

int get_flag(ac, av)
{

}

// flag meanings
// 'i' = integers only, meaning a string containing a single sign and only digits
// 'c' = characters only, meaning a string with letters only and '-' char
// 0: contains only expected type
// -1: invalid characters

// error list ft_checksyntax
// 0: success
// -1: invalid format "98j8" or "--s1mple"
// -2: provided input is not within int range
// -3: missing ints list to sort or excessive flag input

int	ft_checksyntax(char **cmdl)
{
	int i = 0; // tracks number of ints
	int j = 0; // tracks number of flags

	while (cmdl[i])
	{
		if (ft_checkchars(cmdl[i], 'i') < 0)
			break ;
		else if (!ft_checkrange(cmdl[i]))
			return (-2);
		i++;
	}
	while (i > 0 && j < 2 && cmdl[i + j])
	{
		if (ft_checkchars(cmdl[i + j], 'c') != 0)
			return (-1);
		j++;
	}
	if (i == 0 || j == 2)
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

int	parser(char **cmdl, t_stack *a, t_bench *bench)
{

	if (ft_checksyntax(cmdl) < 0 || ft_checkdups(cmdl) < 0) //verifica ints e depois flags
		return (-1);
	else if (tokenizer(cmdl, bench) < 0)
		return (-1)


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


void	init_data(t_stack *a, t_stack *b, t_bench bench)
{
	*a = NULL;
	*b = NULL;
	bench = NULL;
}

int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	t_bench bench;
	char **cmdline;

	if (ac > 1)
	{
		init_data(&a, &b, bench);
		if (parser(lexer(ac, av), &a, bench) < 0)
			write(2, "Error\n", 6);
		sort(a, b, bench);
	}
	free_exit(a, b, bench);
	return (0);

}
