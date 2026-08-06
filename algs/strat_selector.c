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
	if (bench->disorder == 0.0f)
		return ;
	if (!bench->strategy)
		bench->strategy = 4;
	if (bench->strategy == 1)
		simple_algorithm(a, b);
 	else if (bench->strategy == 2)
		medium_algorithm(a, b);
	else if (bench->strategy == 3)
		complex_algorithm(a, b);
	else if (bench->strategy == 4)
		adaptive_algorithm(bench, a, b);
	if (compute_disorder(a) || get_length(b) > 0)
		printf("error: stack is not sorted\n");
	return ;
}
