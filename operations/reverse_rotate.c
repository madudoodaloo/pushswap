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

void	rr_commands(t_stack** head_a, t_stack** head_b, char stack)
{
	if(stack == 'a')
	{
		register_move("rra\n");
		rra(head_a);
	}
	if(stack == 'b')
	{
		register_move("rrb\n");
		rrb(head_b);
	}
	if(stack == 'r')
	{
		register_move("rrr\n");
		rrr(head_a, head_b);
	}
}