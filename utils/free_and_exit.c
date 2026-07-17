/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 03:56:29 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/15 03:56:29 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	ft_error(int error, t_stack **a, char **cmdline)
{
	if (cmdline)
		free_matrix(cmdline);
	if (a && *a)
		free_stack(a);
	ft_fprintf(STDERR_FILENO, "Error\n");
	exit(error);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_exit(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}
