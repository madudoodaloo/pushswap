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

void	ft_registermoves(char *line, t_bench *bench)
{
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
	bench->moves.total += 1;
}


void	get_moves(t_bench *bench)
{
	char *line;

	while (1)
	{
		line = get_next_line(1);
		if (line == NULL)
			break ;
		ft_countmove(line, bench);
		free(line);
	}
}