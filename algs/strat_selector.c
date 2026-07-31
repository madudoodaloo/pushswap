/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 02:48:29 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/16 02:48:29 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	strategy_selector(t_stack **a, t_stack **b, t_bench *bench)
{
	if (!bench->strategy)
		bench->strategy = 4;
	else if (bench->strategy == 1)
		simple_algorithm(a, b);
	else if (bench->strategy == 2)
		medium_algorithm(a, b);
	else if (bench->strategy == 3)
		complex_algorithm(a, b);
	if (bench->strategy == 4)
		adaptive_algorithm(bench->disorder, bench->elements, a, b);
	//printf("%d\n", bench->strategy);
	return ; 
}
