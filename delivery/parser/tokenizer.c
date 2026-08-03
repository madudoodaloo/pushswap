/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 04:27:39 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/15 04:27:39 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_getoptions(char *option, char info)
{
	static int	bench;
	static int	strat;

	if (info == 'i')
		return (bench * 10 + strat);
	if (!bench && !ft_strncmp(option, BENCH, 8))
		bench++;
	else if (!strat && !ft_strncmp(option, SIMPLE, 9))
		strat += 1;
	else if (!strat && !ft_strncmp(option, MEDIUM, 9))
		strat += 2;
	else if (!strat && !ft_strncmp(option, COMPLEX, 10))
		strat += 3;
	else if (!strat && !ft_strncmp(option, ADAPTIVE, 11))
		strat += 4;
	else
		return (-1);
	return (0);
}

static int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}

void	tokenizer(char **cmdl, t_stack **a, t_bench *bench)
{
	int	options;
	int	max;
	int	i;

	options = ft_getoptions(NULL, 'i');
	max = ft_matrixlen(cmdl);
	bench->benchmark = options / 10;
	bench->strategy = options % 10;
	i = -1;
	while (cmdl[++i] && i < max)
		if (ft_checkint(cmdl[i]) == 0)
			ft_node_addback(a, ft_nodenew(ft_atoi(cmdl[i])));
	max -= options / 10 + (options % 10 > 0);
	bench->elements = max;
	bench->disorder = compute_disorder(a);
}
