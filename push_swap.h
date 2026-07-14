/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 03:55:36 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/12 03:55:36 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BENCH	"--bench" // 1
# define SIMPLE "--simple" // 2
# define MEDIUM "--medium" // 3
# define COMPLEX "--complex" // 4
# define ADAPTIVE "--adaptive" // 5


typedef struct s_stack
{
	int n;
	int index;
	struct s_stack *next;
}	t_stack;

typedef struct s_moves
{
	int total;
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}	t_moves;


typedef struct s_bench
{
	bool benchmark; //should only write to stderr when the flag is present.
	char *strategy; //selected strategy name
	char *complexity; //complexity class of the selected strategy
	t_moves *moves; // total number of ops and count of each op type.
	int performance; // added an extra display on the bench, rating the program on performance
}	t_bench;


#endif
