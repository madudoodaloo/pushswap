/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 05:31:06 by masilva-          #+#    #+#             */
/*   Updated: 2026/08/05 05:31:06 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int n_per_chunk_calc(t_stack **head, int chunk)
{
    int range;
    int length;

    range = (highest_with_cieling(head, 0, 0) + 1) - lowest_with_floor(head, 0, 0);
    length = get_length(head);
    if (get_length(head) > 400)
        return (get_length(head) * 2 / chunk);
    else
	    return (get_length(head) / chunk);
}


int	is_sorted(t_stack **stack_a)
{
	t_stack	*cursor;

	cursor = *stack_a;
	while (cursor->next)
	{
		if (cursor->n > cursor->next->n)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}
