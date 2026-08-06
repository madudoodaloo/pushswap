/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:29:12 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/08/06 20:29:12 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **receiver, t_stack **donor)
{
	t_stack	*b1;

	if (!(*donor))
		return ;
	b1 = *donor;
	*donor = (*donor)->next;
	if (*receiver)
		b1->next = *receiver;
	else
		b1->next = NULL;
	*receiver = b1;
}

void	p_commands(t_stack **head_a, t_stack **head_b, char stack)
{
	if (stack == 'a')
	{
		register_move(get_bench(NULL), "pa\n");
		push(head_a, head_b);
	}
	if (stack == 'b')
	{
		register_move(get_bench(NULL), "pb\n");
		push(head_b, head_a);
	}
}
