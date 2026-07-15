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

# define BENCH "--bench" // 10
# define SIMPLE "--simple" // 1
# define MEDIUM "--medium" // 2
# define COMPLEX "--complex" // 3
# define ADAPTIVE "--adaptive" // 4

# define WHITESPACES "\t\n\v\f\r " // 9 to 13 and 32 ascii values

typedef struct s_stack
{
	int n;
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
	int strategy; //selected strategy id
	int performance; // added an extra display on the bench, rating the program on performance
	int elements; // total number of elements given
	float disorder;
	t_moves moves; // total number of ops and count of each op type.
}	t_bench;

/* parser.c */
char	**lexer(int ac, char **av);
int	parser(char **cmdl, t_stack *a, t_bench *bench);

/* tokenizer.c */
void	tokenizer(char **cmdl, t_stack *a, t_bench *bench);

/* option_handler.c */
int	ft_getoptions(char *option, char info);

/* utils/ft_split_strs.c */
char	**ft_split_strs(char const *str, char *skip);

/* utils/ft_atol.c */
long int	ft_atol(char *str);

/* utils/parsing.c */
void free_matrix(char **matrix);

/* utils/print */
void	ft_printbench(t_bench bench);
void	ft_printstack(t_stack *stack);

#endif
