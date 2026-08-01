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
	return ("NONE");
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

void	ft_printbench(int fd, t_bench *bench)
{
	int	decimals;

	if (!bench->benchmark)
		return ;
	//ft_fprintf(fd, "[bench] wrote to fd:  %d\n", fd);
	//ft_fprintf(fd, "[bench] --bench:  %s\n", bench->benchmark > 0 ? "yes" : "no");
	//ft_fprintf(fd, "[bench] elements:  %d\n", bench->elements);
	//ft_fprintf(fd, "remove above\n");
	
	ft_fprintf(fd, "[bench] disorder:  %d.", (int)bench->disorder);
	decimals = (int)(bench->disorder * 100) % 100;
	if (decimals < 10)
		ft_fprintf(fd, "0%d%%\n", decimals);
	else
		ft_fprintf(fd, "%d%%\n", decimals);
	ft_fprintf(fd, "[bench] strategy:  %s\n",
		get_strategy_name(bench->strategy));
	ft_fprintf(fd, "[bench] total_ops: %d\n", bench->moves.total);
	ft_fprintf(fd, "[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		bench->moves.sa, bench->moves.sb, bench->moves.ss, 
		bench->moves.pa, bench->moves.pb);
	ft_fprintf(fd, "[bench] ra:  %d  rb:  %d  rr:  %d"
		"  rra:  %d  rrb:  %d  rrr:  %d\n",
		bench->moves.ra, bench->moves.rb, bench->moves.rr, 
		bench->moves.rra, bench->moves.rrb, bench->moves.rrr);
	ft_fprintf(fd, "[bench] performance: %s\n", 
		performance_benchmark(bench->elements, bench->moves.total));
}
