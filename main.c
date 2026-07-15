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
	if (!ft_islower(*str) && ft_strncmp(str, "--", 2) != 0)
		return ()
	while ()
	if (type == 'd')
	{
		while (*str)
		{
			if (*str == '-' || *str == '+')
				i++;
			if (!ft_isdigit(*str))

		}
		
	}
	int letters;
	int dash;
	int plus;
	int sign;
	int digits;

	if (type == 'd')
		return (sign)

	while (*str)
	{
		if (type == 'd'  )
			digits++;
		else if (ft_islower(*str))
			letters++;
		else if (*str == '-')
			dash++;
		else if (*str == '+')
			plus++;
		else 
			return (-1);
		str++;
	}
	if (plus > 1 || plus > 0 && dash > 0 || type == 'd' && )
		return (-1);
	if ()
	{
		if ((type == 'c' && letters > 0 && !digits && )|| \
				(type == 'd' && digits > 0 && !letters))
			return (0);
		else if ()
}

int get_flag(ac, av)
{

}

// flag meanings
// 'i' = integers only, meaning a string containing a single sign and only digits
// 'c' = characters only, meaning a string with letters only and '-' char
// 1: contains only opposite type
// 0: contains only expected type
// -1: mixed characters

// error list ft_checksyntax
// 0: success
// -1: invalid format "98j8" or "--s1mple"
// -2: provided input is not within int range
// -3: missing ints list to sort
// -4: ./push 1 2 3 --bench 4 5 6 not accepted
int	ft_checksyntax(char **cmdl)
{
	int i = 0;
	int j = 0;
	int flag;
	while (cmdl[i])
	{
		flag = ft_checkchars(cmdl[i], 'i');
		if (flag == -1)
			return (-1)
		if (flag == 1)
			break ;
		else if (!ft_checkrange(cmdl[i]))
			return (-2);
		i++;
	}
	if (i == 0)
		return (-3);
	while (cmdl[i + j])
	{
		if (ft_checkchars(cmdl[i + j], 'c') != 0)
			return (-1);
		else if (j > 1)
			return (-4);
		j++;
	}
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
