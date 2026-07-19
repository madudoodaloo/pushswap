#include "../push_swap.h"

void	rra(t_stack** head)
{
	t_stack*	node;


	if(head && *head && (*head)->next)
	{
		node = *head;
		while(node->next->next)
		{
			node = node->next;
		}
		node->next->next = *head;
		*head = node->next;
		node->next = NULL;
	}
}

void	rrb(t_stack** head)
{
	rra(head);
}

void	rrr(t_stack** head_a, t_stack** head_b)
{
	rra(head_a);
	rra(head_b);
}

//viaja até o penúltimo nódulo 
//mete o último nódulo apontar para o primeiro
//torna o último nódulo como primeiro
//anula a ligação entre o último e o penúltimo nódulo

void	rr_commands(t_stack** head_a, t_stack** head_b, char command, char stack)
{
	write(1, "rr", 2);
	if(stack == 'a')
	{
		write(1, "a", 1);
		write(1, "\n", 1);
		rra(head_a);
	}
	if(stack == 'b')
	{
		write(1, "b", 1);
		write(1, "\n", 1);
		rrb(head_b);
	}
	if(stack == 'r')
	{
		write(1, "r", 1);
		
		rrr(head_a, head_b);
	}
}