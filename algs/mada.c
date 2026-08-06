/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 05:30:07 by masilva-          #+#    #+#             */
/*   Updated: 2026/08/05 05:30:07 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* 
static void	putinb(t_stack **a, t_stack **b, int size)
{
	int	chunk;
	int	counterb;

	chunk = 30;

	counterb = 0;
	while (*a)
	{
		if ((*a)->index < chunk)
		{
			p_commands(a, b, 'b');
			counterb++;
		}
		else if (counterb == chunk)
		{
			if (size > 100)
			{
				chunk += 30;
			}
			else
				chunk += 15;
		}
		else
			getto_a_top(a, indexchecker(a, (*a)->index));
	}
	printf("leaving putinb\n");
	ft_printstack(*a);
	ft_printstack(*b);

}

static int	putina(t_stack **a, t_stack **b, int *big, int index)
{
	if ((*a) && (*a)->next && (*a)->n > (*a)->next->n)
	{
		s_commands(a, NULL, 'a');
		(*big)--;
		index = indexchecker(b, *big);
	}
	else if ((indexchecker(b, ((*big) - 1)) == 0))
	{
		p_commands(a, b, 'a');
		index = indexchecker(b, (*big));
	}
	else if (index == 2 && (indexchecker(b, ((*big) - 1)) == 0))
	{
		p_commands(a, b, 'a');
		(*big)--;
		r_commands(a, b, 'b');
		p_commands(a, b, 'a');
		(*big)--;
		s_commands(a, b, 'a');
		index = indexchecker(b, (*big));
	}
	index = putina2(a, b, big, index);
	return (index);
}

int	putina2(t_stack **a, t_stack **b, int *big, int index)
{
	if (index == 1 && (indexchecker(b, (*big) - 1)) == 0)
	{
		s_commands(a, b, 'b');
		index = indexchecker(b, (*big));
	}
	else if (indexchecker(b, (*big)) == 0)
	{
		p_commands(a, b, 'a');
		(*big)--;
		index = indexchecker(b, (*big));
	}
	else
	{
		getto_b_top(b, index);
		index = indexchecker(b, (*big));
	}
	return (index);
}

void	medium_algorithm(t_stack **a, t_stack **b)
{
	int	index;
	int	big;

	putinb(a, b, (get_bench(NULL))->elements);
	big = getbiggestindex(b);
	printf("big: %d\n", big);
	index = indexchecker(b, big);
	printf("index: %d\n", index);
	while ((*b) && index == indexchecker(b, big))
		index = putina(a, b, &big, index);
	if ((*b) == NULL && (*a)->n > (*a)->next->n)
		s_commands(a, b, 'a');
}
 */