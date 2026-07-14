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

int flag_checker(ac, av)
{

}
// sö pode receber uma flag de selector no mäximo, e bench opcional.
// 1o, lista formatada de ints da stack a, depois flags.
int parser(ac, av)
{

}


void	init_data(t_stack a, t_stack b, t_bench bench, char **av)
{
	a = NULL;
	b = NULL;
	bench = NULL;
}

int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	t_bench bench;

	if (ac > 1)
	{
		int mode = parser((ac, av) < 0);
		if (mode < 0)
			write(2, "Error\n", 6);
		init_data(a, b, bench, mode);
		sort(a, b, bench);
	}
	free_exit(a, b, bench);
	return (0);

}