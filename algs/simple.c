/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 06:04:40 by masilva-          #+#    #+#             */
/*   Updated: 2026/08/05 06:04:40 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int get_neighbor_diff(t_stack *curr)
{
    if (!curr || !curr->next)
        return (0);
    int diff = curr->index - curr->next->index;
    if (diff == 1 || diff == -1)
        return (0);
    return (curr->index - curr->next->index);
}

void	selection_sort(t_stack **a, t_stack **b)
{
    int diff;
    
    while (compute_disorder(a) > 0.0f)
    {
        diff = get_neighbor_diff(*a);        
        if (diff != 0)
        {
            if (diff > 0)
                pb(a, b);
            else
            {
                if (get_neighbor_diff((*a)->next) == 0)
                {
                    if (*b && (*b)->next)
                        rr(a, b);
                    else
                        ra(a);
                }
                else
                {
                    if (*b && (*b)->next)
                        rb(b);
                    else
                        ra(a);
                }
            }
        }
        else
            ra(a);
    }
}

void sort_simple(t_stack **a, t_stack **b)
{
    while (*b)
        pa(a, b);
}

void	simple_algorithm(t_bench *bench, t_stack **a, t_stack **b)
{
	int cost;
	int iter;

	t_stack *cursor;

	cursor = *a;
	iter = 0;
	while (cursor && !compute_disorder(a))
	{
		if (check_position(cursor->index) < 0)
			
			if (cost(cursor, a) > cost(cursor, b))
				extract_node(cursos->index);
			else
				ra()

		{
			if (cost(cursor, a) > cost(cursor, b))
			{
				pb();
				if (cursor->index < iter)
					iter++;
			}

			if ()
		}

	}
	
}