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

int	indexchecker(t_stack **stack, int i)
{
	t_stack	*cursor;
	int		position;
	int		flag;

	position = 0;
	flag = -1;
	cursor = *stack;
	while (cursor)
	{
		if (cursor->index == i)
		{
			flag = 0;
			break ;
		}
		position++;
		cursor = cursor->next;
	}
	if (flag == -1)
		return (-1);
	return (position);
}

// iterates through the stack, returns the biggest found index
// ex: 1 [23] 5 4 7
// returns: [1]
int	getbiggestindex(t_stack **stack)
{
	t_stack	*cursor;
	int		big;

	cursor = *stack;
	big = cursor->index;
	while (cursor)
	{
		if (cursor->index > big)
			big = cursor->index;
		cursor = cursor->next;
	}
	return (big);
}

void	getto_a_top(t_stack **a, int index)
{
	if (index == -1)
		return ;
	if (index < (get_length(a) / 2))
		r_commands(a, NULL, 'a');
	else
		rr_commands(a, NULL, 'a');
}

void	getto_b_top(t_stack **b, int index)
{
	if (index == -1)
		return ;
	if (index < (get_length(b) / 2))
		r_commands(NULL, b, 'b');
	else
		rr_commands(NULL, b, 'b');
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
