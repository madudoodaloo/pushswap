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

// Low disorder: if disorder < 0.2, your chosen method must run in O(n2) time.
// Medium disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in O(n√n) time.
// High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n) time

void	adaptive_algorithm(float disorder, int elements, t_stack **a, t_stack **b)
{
	if (!a || !*a || disorder == 0.0f)
		return ;
	if (elements <= 5)
	{
		//sort_small(a, b, size);
		return ;
	}
	disorder /= 100.0f;
	if (disorder < 0.2f)
		simple_algorithm(a, b);
	else if (disorder < 0.5f)
		medium_algorithm(a, b);
	else
		complex_algorithm(a, b);
}

