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

void	init_data(t_stack *a, t_stack *b, t_bench bench)
{
	*a = NULL;
	*b = NULL;
	bench = NULL;
}

int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	t_bench bench;

	if (ac > 1)
	{
		init_data(&a, &b, &bench);
		if (parser(lexer(ac, av), &a, &bench) < 0)
			write(2, "Error\n", 6);
		else
		{
			ft_printstack(a);
			ft_printbench(bench);
		}
		//sort(&a, &b, &bench);
	}
	free_exit(a, b, bench);
	return (0);

}
