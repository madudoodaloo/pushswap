/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:29:31 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/08/06 20:29:31 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **head)
{
	t_stack	*node;

	if (head && *head && (*head)->next)
	{
		node = *head;
		while (node->next->next)
		{
			node = node->next;
		}
		node->next->next = *head;
		*head = node->next;
		node->next = NULL;
	}
}

void	rrb(t_stack **head)
{
	rra(head);
}

void	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(head_a);
	rra(head_b);
}

//viaja até o penúltimo nódulo 
//mete o último nódulo apontar para o primeiro
//torna o último nódulo como primeiro
//anula a ligação entre o último e o penúltimo nódulo

void	rr_commands(t_stack **head_a, t_stack **head_b, char stack)
{
	if (stack == 'a')
	{
		register_move(get_bench(NULL), "rra\n");
		rra(head_a);
	}
	if (stack == 'b')
	{
		register_move(get_bench(NULL), "rrb\n");
		rrb(head_b);
	}
	if (stack == 'r')
	{
		register_move(get_bench(NULL), "rrr\n");
		rrr(head_a, head_b);
	}
}
