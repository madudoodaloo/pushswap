#include "../push_swap.h"

int n_per_chunk_calc(t_stack **head, int chunk)
{
    int range;
    int length;

    range = (highest_with_cieling(head, 0, 0) + 1) - lowest_with_floor(head, 0, 0);
    length = get_length(head);
    if (get_length(head) > 400)
        return (get_length(head) * 2 / chunk);
    else
	    return (get_length(head) / chunk);
}

int highest_without_chunk(t_stack **head)
{
	int		highest;
	t_stack	*node;
	
	highest = lowest_with_floor(head, 0, 0);
	node = *head;
	while(node)
	{
		if(node->n > highest && node->block == -1)
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

/*void	push_chunks(t_stack **head_a, t_stack **head_b, int chunk)
{
	t_stack	*node;
	int		check;
	int		i;

	i = 0;
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
}*/

void	push_chunks(t_stack **head_a, t_stack **head_b, int chunk)
{
	t_stack	*node;
	int		i;

	i = 0;
	while (i <= chunk && *head_a)
	{
        node = *head_a;
		while(node && node->block != i)
		{
			node = node->next;
            if(!node)
            {
                node = *head_a;
                i++;
            }
		}
        while((*head_a)->n != node->n)
            faster_way(head_a, node->n, 'a');
        commands(head_a, head_b, 'p', 'b');
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
	int chunk;
	int n_per_chunk;

	chunk = pitagoras(get_length(head_a));
    n_per_chunk = n_per_chunk_calc(head_a, chunk);
	while(chunk >= 0)
	{
		mark_chunk(head_a, chunk, n_per_chunk);
		chunk--;
        printf("%d\n", chunk);
	}
	chunk = pitagoras(get_length(head_a));
	push_chunks(head_a, head_b, chunk);
	while(*head_b)
	{
		sort_chunk(head_a, head_b);
		chunk--;
	}
}
