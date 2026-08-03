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

	highest = highest_with_cieling(head, 0, 0);
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

	i = 0;
	while (i < chunk && *head_a)
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

void	sort_chunk(t_stack **head_a, t_stack **head_b, int chunk)
{
	int		chunk_length;
	int		i;
	int		highest;
	t_stack	*node;

	chunk_length = 0;
	i = 0;
	node = *head_b;
	while (node)
	{
		if (node->block == chunk)
		chunk_length++;
		node = node->next;
	}
	while (i < chunk_length && *head_b)
	{
		highest = highest_with_cieling(head_b, 0, 0);
		while((*head_b)->n != highest)
			faster_way(head_b, highest, 'b');
		commands(head_a, head_b, 'p', 'a');
		i++;
	}
}

void medium_algorithm(t_stack **head_a, t_stack **head_b)
{
	int length;
	int chunk;

	length = get_length(head_a);
	chunk = pitagoras(length);
	while(chunk > 0)
	{
		mark_chunk(head_a, chunk, pitagoras(length));
		chunk--;
	}
	chunk = pitagoras(length);
	push_chunks(head_a, head_b, chunk);
	while(*head_b)
	{
		sort_chunk(head_a, head_b, chunk);
		chunk--;
	}
}


/* 
//calcula o numero minimo existente no subgrupo
int chunk_boundary(t_stack** head, int chunk)
{
	int	length;
	int	min;
	int	max;
	int	range; // no de elementos

	length = get_length(head);
	min = lowest_with_floor(head, 0, 0);
	max = highest_with_cieling(head, 0, 0);
	range = (max - min) + 1;
	return (min + ((chunk * range) / pitagoras(length)));
}

//encontra todos os elementos do subgrupo no stack A e puxa-os para o B
void push_chunk(t_stack** head_a, t_stack** head_b, int chunk)
{
	int i;
	int length;
	int chunk_min;
	int chunk_max;

	i = 0;
	length = get_length(head_a);
	chunk_min = chunk_boundary(head_a, chunk);
	//printf("bound %d", chunk_min)
	chunk_max = chunk_boundary(head_a, (chunk + 1));
	while (i < length)
	{
		if((chunk_min <= (*head_a)->n) && ((*head_a)->n < chunk_max))
		{
			commands(head_a, head_b, 'p', 'b');
		}
		else
			commands(head_a, head_b, 'r', 'a');
		i++;
	}
}

void medium_algorithm(t_stack** head_a, t_stack** head_b)
{
	int length;
	int chunk;
	int highest;

	length = get_length(head_a);
	chunk = pitagoras(length) - 1;
	while(chunk >= 0)
	{
		push_chunk(head_a, head_b, chunk);
		while(*head_b)
		{
			highest = highest_with_cieling(head_b, 0, 0);
			while((*head_b)->n != highest)
				faster_way(head_b, highest, 'b');
			commands(head_a, head_b, 'p', 'a');
		}
		chunk--;
	}
}
 */