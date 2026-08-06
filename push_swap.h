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
# include "libft/libft.h"
# include "ft_fprintf/ft_fprintf.h"
# include "get_next_line/get_next_line_bonus.h"

# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int				n;
	int				block;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_moves;

typedef struct s_bench
{
	bool	benchmark; //should only write to stderr when the flag is present.
	int		strategy; //selected strategy id
	int		performance; // extra display, rating the program on performance
	int		elements; // total number of elements given
	float	disorder;
	t_moves	moves; // total number of ops and count of each op type.
}	t_bench;

/********************************/
/*			./parser/			*/
/********************************/

// lexer.c
char	**lexer(int ac, char **av);

// parser.c
int		parser(char **cmdl, t_stack **a, t_bench *bench);
int		ft_checkint(char *str);

// tokenizer.c
void	tokenizer(char **cmdl, t_stack **a, t_bench *bench);
int		ft_getoptions(char *option, char info);


/********************************/
/*			./bench/			*/
/********************************/

// disorder.c 
float	compute_disorder(t_stack **a);

// moves.c 
t_bench	*get_bench(t_bench *bench);
void	register_move(t_bench *bench, char *line);

// performance.c 
char	*performance_benchmark(int elements, int total_moves);

// print.c 
void	ft_printstack(t_stack *stack);
void	ft_printbench(int fd, t_bench *bench);


/********************************/
/*			./utils/			*/
/********************************/

// free_and_exit.c 
void	ft_error(int error, t_stack **a, char **cmdline);
void	free_matrix(char **matrix);
void	free_exit(t_stack **a, t_stack **b);

// ft_atol.c 
long	ft_atol(char *str);

// ft_split_strs.c 
char	**ft_split_strs(char const *str, char *skip);

// node_utils.c 
t_stack	*ft_nodenew(int value);
void	ft_node_addback(t_stack **stack, t_stack *new_node);


/********************************/
/*		./operations/			*/
/********************************/

// push.c
void	push(t_stack** head_a, t_stack** head_b);
void	p_commands(t_stack** head_a, t_stack** head_b, char stack);

//reverse_rotate.c
void	rra(t_stack** head);
void	rrb(t_stack** head);
void	rrr(t_stack** head_a, t_stack** head_b);
void	rr_commands(t_stack** head_a, t_stack** head_b, char stack);

//rotate.c
void	ra(t_stack** head);
void	rb(t_stack** head);
void	rr(t_stack** head_a,t_stack** head_b);
void	r_commands(t_stack** head_a, t_stack** head_b, char stack);

// swap.c
void	sa(t_stack** head);
void	sb(t_stack** head);
void	ss(t_stack** head_a, t_stack **head_b);
void	s_commands(t_stack** head_a, t_stack** head_b, char stack);

// utils.c
void	commands(t_stack** head_a, t_stack** head_b, char command, char stack);
int		get_length(t_stack** head);
int		pitagoras(int n);

/********************************/
/*		./algorithms/			*/
/********************************/
void	strategy_selector(t_stack **a, t_stack **b, t_bench *bench);
void	simple_algorithm(t_stack** head_a, t_stack** head_b);
void	medium_algorithm(t_stack** head_a, t_stack** head_b);
void	complex_algorithm(t_stack** head_a, t_stack** head_b);
void	adaptive_algorithm(t_bench *bench, t_stack **a, t_stack **b);

//helper functions
int get_length(t_stack** head);
void faster_way(t_stack** head, int number, char chosen_stack);
int lowest_with_floor(t_stack** head, int floor, int floor_check);
int highest_with_cieling(t_stack** head, int ceiling, int ceiling_check);

void	set_index(t_stack **s);
int		is_sorted(t_stack **stack_a);
int		indexchecker(t_stack **stack, int i);
int		getbiggestindex(t_stack **stack);
void	getto_a_top(t_stack **a, int index);
void	getto_b_top(t_stack **b, int index);

void	brut_algorithm(t_stack **a, t_stack **b)
void	alg5(t_stack **a, t_stack **b);
void	alg3(t_stack **a);


#endif