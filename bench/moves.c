/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:44:15 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/19 19:44:15 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bench	*get_bench(t_bench *bench)
{
	static t_bench	*address;

	if (bench)
		address = bench;
	return (address);
}

void	register_move(char *line)
{
	t_bench *bench;

	bench = get_bench(NULL);
	if (ft_strncmp(line, "sa\n", 3))
		bench->moves.sa += 1;
	else if (ft_strncmp(line, "sb\n", 3))
		bench->moves.sb += 1;
	else if (ft_strncmp(line, "ss\n", 3))
		bench->moves.ss += 1;
	else if (ft_strncmp(line, "pa\n", 3))
		bench->moves.pa += 1;
	else if (ft_strncmp(line, "pb\n", 3))
		bench->moves.pb += 1;
	else if (ft_strncmp(line, "ra\n", 3))
		bench->moves.ra += 1;
	else if (ft_strncmp(line, "rb\n", 3))
		bench->moves.rb += 1;
	else if (ft_strncmp(line, "rr\n", 3))
		bench->moves.rr += 1;
	else if (ft_strncmp(line, "rra\n", 4))
		bench->moves.rra += 1;
	else if (ft_strncmp(line, "rrb\n", 4))
		bench->moves.rrb += 1;
	else if (ft_strncmp(line, "rrr\n", 4))
		bench->moves.rrr += 1;
	else
		ft_fprintf(STDERR_FILENO, "Invalid move\n");
	ft_fprintf(STDOUT_FILENO, "%s", line);
	bench->moves.total += 1;

}
