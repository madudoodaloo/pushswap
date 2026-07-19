#include "../push_swap.h"

void	push(t_stack** receiver, t_stack** donor)
{
	t_stack*	b1;
	//t_stack*	temp;

	if(!(*donor))
		return;
	b1 = *donor;
	*donor = (*donor)->next;
	if(*receiver)
		b1->next = *receiver;
	else
		b1->next = NULL;
	*receiver = b1;
}

void	p_commands(t_stack** head_a, t_stack** head_b, char stack)
{
	write(1, "p", 1);
	if(stack == 'a')
	{
		write(1, "a", 1);
		write(1, "\n", 1);
		push	(head_a, head_b);
	}
	if(stack == 'b')
	{
		write(1, "b", 1);
		write(1, "\n", 1);
		push	(head_b, head_a);
	}
}