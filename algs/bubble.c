/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:57:30 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/08/06 20:07:36 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	bubble_check(t_stack **head)
{
	int		fails;
	t_stack	*node;

	fails = 0;
	node = *head;
	while (node)
	{
		if (node->next && node->n > node->next->n)
			fails++;
		node = node->next;
	}
	return (fails);
}

static void	swap(t_stack **head)
{
	if ((*head)->block == 1)
	{
		if ((*head)->n > (*head)->next->n)
		{
			(*head)->block = 0;
			commands(head, head, 's', 'a');
			(*head)->block = 1;
		}
	}
	else if ((*head)->next->block != 1)
	{
		if ((*head)->n > (*head)->next->n)
			commands(head, head, 's', 'a');
	}
	commands(head, head, 'r', 'a');
}

void	bubble_algorithm(t_stack **head)
{
	int	n;

	(*head)->block = 1;
	while (bubble_check(head) != 0)
	{
		n = get_length(head);
		while (n != 0)
		{
			swap(head);
			n--;
		}
	}
}
