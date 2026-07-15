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

#include "push_swap.h"

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

void	tokenizer(char **cmdl, t_stack *a, t_bench *bench)
{
	int options;
	int max;

	options = ft_getoptions(cmdl, 'i');
	max = ft_matrixlen(cmdl);
	max -= options / 10 + (options % 10 > 0);
	bench->elements = max; //we will be sorting based in disorder rate, not elements (?)
	bench->benchmark = options / 10;
	bench->strategy = options % 10;
	while (cmdl[i] && i < max)
		ft_lstaddback(&a, ft_lstnew(ft_atoi(cmdl[i++])))
	bench->disorder = compute_disorder(a);
	// missing moves init if benchmark bool == 1
	// missing performance only after execution
}
