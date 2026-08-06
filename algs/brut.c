/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:48:51 by masilva-          #+#    #+#             */
/*   Updated: 2026/08/05 20:48:51 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	alg3(t_stack **a)
{
	int		big;
	t_stack	*stack;

	stack = *a;
	big = stack->n;
	while (stack)
	{
		if (stack->n > big)
			big = stack->n;
		stack = stack->next;
	}
	if ((*a)->n == big)
		r_commands(a, NULL, 'a');
	else if ((*a)->next->n == big)
		rr_commands(a, NULL, 'a');
	if ((*a)->n > (*a)->next->n)
		s_commands(a, NULL, 'a');
}

static int	getsmallest(t_stack **a)
{
	int		position;
	t_stack	*cursor;
	t_stack	*smallest;

	cursor = *a;
	smallest = *a;
	position = 0;
	while (cursor)
	{
		if (cursor->n < smallest->n)
			smallest = cursor;
		cursor = cursor->next;
	}
	cursor = *a;
	while (cursor != smallest)
	{
		position++;
		cursor = cursor->next;
	}
	return (position);
}

static void	pushsmallest(t_stack **a, t_stack **b, int position, int flag)
{
	if (position > 2)
	{
		if (flag == 1)
			position = 4 - position;
		else
			position = 5 - position;
		while (position)
		{
			rr_commands(a, b, 'a');
			position--;
		}
	}
	else
	{
		while (position)
		{
			r_commands(a, b, 'a');
			position--;
		}
	}
	p_commands(a, b, 'b');
}

void	alg5(t_stack **a, t_stack **b)
{
	t_stack	*cursor;
	int		position;

	cursor = *a;
	if (get_length(&cursor) == 5)
	{
		position = getsmallest(&cursor);
		pushsmallest(a, b, position, 0);
		cursor = *a;
	}
	position = getsmallest(&cursor);
	pushsmallest(a, b, position, 1);
	if (!is_sorted(a))
		alg3(a);
	while (*b)
		p_commands(a, b, 'a');
}

void	brut_algorithm(t_stack **a, t_stack **b)
{
	int size;

	size = get_length(head_a);
	if (size <= 3)
		alg3(head_a);
	else if (size <= 5)
		alg5(head_a, head_b);
	else
		return (0);
	return (1);
}