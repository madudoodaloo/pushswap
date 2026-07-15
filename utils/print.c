/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 08:29:13 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/15 08:29:13 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this has ai intervention
#include "../push_swap.h"

static char	*get_strategy_name(int strategy_id)
{
	if (strategy_id == 1)
		return ("Simple / O(n^2)");
	if (strategy_id == 2)
		return ("Medium / O(n log n)");
	if (strategy_id == 3)
		return ("Complex / O(n log n)");
	if (strategy_id == 4)
		return ("Adaptive / O(n\\sqrt{n})");
	return ("Error");
}


void	ft_printstack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	current = stack;
	ft_printf("Stack elements: ");
	while (current)
	{
		ft_printf("%d", current->n);
		if (current->next)
			ft_printf(" -> ");
		current = current->next;
	}
	ft_printf("\n");
}

void	ft_printbench(t_bench *bench)
{
	//int	disorder_whole;
	//int	disorder_fraction;

	// Only execute if the --bench flag was actually parsed
	//if (!bench.benchmark)
	//	return ;

	// Convert float disorder to whole and fractional digits
	//disorder_whole = (int)bench.disorder;
	//disorder_fraction = (int)((bench.disorder - disorder_whole) * 100);
	//if (disorder_fraction < 0)
	//	disorder_fraction = -disorder_fraction;

	// Print lines matching the console layout exactly
	//ft_printf("[bench] disorder:  %d.%02d%%\n", disorder_whole, disorder_fraction);
	ft_printf("[bench] elements:  %d\n", bench->elements);
	ft_printf("[bench] strategy:  %s\n", get_strategy_name(bench->strategy));
	//ft_printf("[bench] total_ops: %d\n", bench.moves.total);
	
	//ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
	//	bench.moves.sa, bench.moves.sb, bench.moves.ss, 
	//	bench.moves.pa, bench.moves.pb);
		
	//ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d  rra:  %d  rrb:  %d  rrr:  %d\n",
	//	bench.moves.ra, bench.moves.rb, bench.moves.rr, 
	//	bench.moves.rra, bench.moves.rrb, bench.moves.rrr);
}
