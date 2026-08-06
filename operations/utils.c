/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:29:53 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/08/06 20:29:53 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	commands(t_stack **head_a, t_stack **head_b, char command, char stack)
{
	if (command == 's')
		s_commands(head_a, head_b, stack);
	else if (command == 'p')
		p_commands(head_a, head_b, stack);
	else if (command == 'r')
		r_commands(head_a, head_b, stack);
	else if (command == 'd')
		rr_commands(head_a, head_b, stack);
}

int	get_length(t_stack **head)
{
	t_stack	*node;
	int		length;

	length = 0;
	node = *head;
	while (node)
	{
		length++;
		node = node->next;
	}
	return (length);
}
