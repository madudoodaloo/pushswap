/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 02:15:43 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/29 02:15:43 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Low disorder: if disorder < 0.2, O(n2) time.
// Medium disorder: if 0.2 ≤ disorder < 0.5, O(n√n) time.
// High disorder: if disorder ≥ 0.5, O(n log n) time

static void	record_strat(float disorder, int *strategy)
{
	if (disorder < 0.2f)
		*strategy = 5;
	else if (disorder < 0.5f)
		*strategy = 6;
	else
		*strategy = 7;
}

void	adaptive_algorithm(t_bench *bench, t_stack **a, t_stack **b)
{
	float	disorder;

	disorder = bench->disorder;
	if (!a || !*a || disorder == 0.0f)
		return ;
	disorder /= 100.0f;
	record_strat(disorder, &(bench->strategy));
	if (disorder < 0.2f)
		simple_algorithm(a, b);
	else if (disorder < 0.5f)
		medium_algorithm(a, b);
	else
		complex_algorithm(a, b);
}
