#include "../push_swap.h"

//colocar 0 no último argumento fará com que a função ignore o segundo argumento 
int lowest_with_floor(t_stack** head, int floor, int floor_check)
{
	t_stack*	node;
	int		lowest;
	int		true_lowest;

	node = *head;
	lowest = (*head)->n;
	true_lowest = lowest;
	while(node)
	{
		if((node->n < lowest) && (node->n > floor))
			lowest = node->n;
		if(node->n < true_lowest)
			true_lowest = node->n;
		node = node->next;
	}
	if (floor_check == 0)
		return (true_lowest);
	return (lowest);
}

//colocar 0 no último argumento fará com que a função ignore o segundo argumento 
int highest_with_cieling(t_stack** head, int ceiling, int ceiling_check)
{
	t_stack*	node;
	int		highest;
	int		true_highest;

	node = *head;
	highest = node->n;
	true_highest = highest;
	while(node)
	{
		if((node->n > highest) && (node->n < ceiling))
			highest = node->n;
		if(node->n > true_highest)
			true_highest = node->n;
		node = node->next;
	}
	if(ceiling_check == 0)
		return (true_highest);
	return (highest);
}

void faster_way(t_stack** head, int number, char chosen_stack)
{
	t_stack* node;
	int length;
	int number_len;

	node = *head;
	length = 0;
	while(node->next)
	{
		length++;
		node = node->next;
	}
	node = *head;
	while((node) && (node->n != number))
	{
		number_len++;
		node = node->next;
	}
	if(number_len > length/2)
		commands(head, head, 'd', chosen_stack);
	else
		commands(head, head, 'r', chosen_stack);
}

void	simple_algorithm(t_stack** head_a, t_stack** head_b)
{
	int	lowest;

	while(*head_a)
	{
		lowest = lowest_with_floor(head_a, 0, 0);
		while((*head_a)->n != lowest)
			{
				faster_way(head_a, lowest, 'a');
			}
		commands(head_a, head_b, 'p', 'b');
	}
	while(*head_b)
		commands(head_a, head_b, 'p', 'a');
}