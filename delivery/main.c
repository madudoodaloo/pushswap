/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 03:22:37 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/14 03:22:37 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_stack **a, t_stack **b, t_bench *bench)
{
	*a = NULL;
	*b = NULL;
	bench->benchmark = false;
	bench->strategy = 0;
	bench->performance = 0;
	bench->elements = 0;
	bench->disorder = 0.0;
	bench->moves.total = 0;
	bench->moves.sa = 0;
	bench->moves.sb = 0;
	bench->moves.ss = 0;
	bench->moves.pa = 0;
	bench->moves.pb = 0;
	bench->moves.ra = 0;
	bench->moves.rb = 0;
	bench->moves.rr = 0;
	bench->moves.rra = 0;
	bench->moves.rrb = 0;
	bench->moves.rrr = 0;
}

int	push_swap(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	char	**cmdline;

	if (ac > 1)
	{
		init_data(&a, &b, &bench);
		get_bench(&bench);
		cmdline = lexer(ac, av);
		parser(cmdline, &a, &bench);
		//ft_printstack(a);
		strategy_selector(&a, &b, &bench);
		//ft_printstack(a);
		ft_printbench(STDERR_FILENO, &bench);
		free_exit(&a, &b);
	}
	return (0);
}

int	main(int ac, char **av)
{
	return (push_swap(ac, av));
}
