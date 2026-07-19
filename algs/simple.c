#include "../push_swap.h"

int	check_lowest(int lowest, int n)
{
	printf("%d < %d | ", n, lowest);
	if(n < lowest)
		return	(n);
	return	(lowest);
}

int	find_lowest(t_stack** head)
{
	t_stack*	node;
	int lowest;

	node = *head;
	lowest = node->n;
	while(node)
	{
		lowest = check_lowest(node->n, lowest);
		printf("%d\n", lowest);
		node = node->next;
	}
	return	(lowest);
}

void faster_way(t_stack** head_a, t_stack** head_b, int lowest)
{
	t_stack* node;
	int length;
	int lowest_len;

	node = *head_a;
	length = 0;
	while(node->next)
	{
		length++;
		node = node->next;
	}
	node = *head_a;
	while(node->n != lowest)
	{
		lowest_len++;
		node = node->next;
	}
	if(lowest_len > length/2)
		commands(head_a, head_b, 'd', 'a');
	else
		commands(head_a, head_b, 'r', 'a');
}

void	simple_algorithm(t_stack** head_a, t_stack** head_b)
{
	int	lowest;

	while(*head_a)
	{
		lowest = find_lowest(head_a);
		while((*head_a)->n != lowest)
			faster_way(head_a, head_b, lowest);
		commands(head_a, head_b, 'p', 'b');
	}
	while(*head_b)
		commands(head_a, head_b, 'p', 'a');
}
