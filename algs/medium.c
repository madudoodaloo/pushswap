#include "../push_swap.h"

//raiz quadrada adaptado a inteiros


int highest_without_chunk(t_stack **head)
{
	int		highest;
	t_stack	*node;
	
	highest = lowest_with_floor(head, 0, 0);
	node = *head;
	while(node)
	{
		if(node->n > highest && node->block == 0)
			highest = node->n;
		node = node->next;
	}
	return (highest);
}

void mark_chunk(t_stack **head, int chunk, int n)
{
	int		highest;
	t_stack	*node;

	highest = 0;
	while (n != 0)
	{
		highest = highest_without_chunk(head);
		node = *head;
		while(node->n != highest)
			node = node->next;
		node->block = chunk;
		n--;
	}
}

void	push_chunks(t_stack **head_a, t_stack **head_b, int chunk)
{
	t_stack	*node;
	int		check;
	int		i;

	i = 1;
	while (i <= chunk && *head_a)
	{
		if ((*head_a)->block == i)
			commands(head_a, head_b, 'p', 'b');
		else
			commands(head_a, head_b, 'r', 'a');
		node = *head_a;
		check = 0;
		while(node && check == 0)
		{
			if(node->block == i)
				check++;
			node = node->next;
		}
		if (check == 0)
			i++;
	}
}

void	sort_chunk(t_stack **head_a, t_stack **head_b)
{
	int		highest;

	while (*head_b)
	{
		highest = highest_with_cieling(head_b, 0, 0);
		while((*head_b)->n != highest)
			faster_way(head_b, highest, 'b');
		commands(head_a, head_b, 'p', 'a');
	}
}

void medium_algorithm(t_stack **head_a, t_stack **head_b)
{
	int range;
	int chunk;
	int n_per_chunk;

	range = (highest_with_cieling(head_a, 0, 0) - lowest_with_floor(head_a, 0, 0)) + 1;
	chunk = pitagoras(get_length(head_a));
	n_per_chunk = range / chunk;
	while(chunk > 0)
	{
		mark_chunk(head_a, chunk, n_per_chunk);
		chunk--;
	}
	chunk = pitagoras(get_length(head_a));
	push_chunks(head_a, head_b, chunk);
	while(*head_b)
	{
		sort_chunk(head_a, head_b);
		chunk--;
	}
}
