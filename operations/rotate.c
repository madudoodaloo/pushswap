#include "../push_swap.h"

void	ra(t_stack** head)
{
	t_stack*	first;
	t_stack*	temp;

	if(head && *head && (*head)->next)
	{
	first = *head;
	temp = *head;
	*head = (*head)->next;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = first;
	first->next = NULL;
	}
}

void	rb(t_stack** head)
{
	ra(head);
}

void	rr(t_stack** head_a, t_stack** head_b)
{
	ra(head_a);
	ra(head_b);
}

//a função vai guardar o ponteiro do primeiro nó (10), torna o segundo nódulo o primeiro da lista
// viaja pela lista (12)
//cola o primeiro ao ultimo (16)
//retira o ponteiro do segundo nódulo (agora primeiro) da lista do primeiro (agora em último)

void	r_commands(t_stack** head_a, t_stack** head_b, char stack)
{
	if(stack == 'a')
	{
		register_move(get_bench(NULL), "ra\n");
		ra(head_a);
	}
	if(stack == 'b')
	{
		register_move(get_bench(NULL), "rb\n");
		rb(head_b);
	}
	if(stack == 'r')
	{
		register_move(get_bench(NULL), "rr\n");
		rr(head_a, head_b);
	}
}