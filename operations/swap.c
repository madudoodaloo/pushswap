/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva-@student.42lisboa.com <masilva-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:29:48 by masilva-@st       #+#    #+#             */
/*   Updated: 2026/08/06 20:29:48 by masilva-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **head)
{
	int	temp;

	if (head && *head && (*head)->next)
	{
		temp = (*head)->next->n;
		(*head)->next->n = (*head)->n;
		(*head)->n = temp;
	}
}

void	sb(t_stack **head)
{
	sa(head);
}

void	ss(t_stack **head_a, t_stack **head_b)
{
	sa(head_a);
	sb(head_b);
}

//uma troca muito simples de números apenas usando uma variável tempirária para
//guardar o primeiro numero a ser metido lá
//guard o segundo numero numa coisa temporária 9
//dá o valor do primeiro numero ao segundo 10
//dá o valor da variável temporária ao primeiro 11

void	s_commands(t_stack **head_a, t_stack **head_b, char stack)
{
	if (stack == 'a')
	{
		register_move(get_bench(NULL), "sa\n");
		sa(head_a);
	}
	if (stack == 'b')
	{
		register_move(get_bench(NULL), "sb\n");
		sb(head_b);
	}
	if (stack == 's')
	{
		register_move(get_bench(NULL), "ss\n");
		ss(head_a, head_b);
	}
}
