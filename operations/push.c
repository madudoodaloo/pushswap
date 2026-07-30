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
	if(stack == 'a')
	{
		ft_fprintf(STDOUT_FILENO, "pa\n");
		push(head_a, head_b);
	}
	if(stack == 'b')
	{
		ft_fprintf(STDOUT_FILENO, "pb\n");
		push(head_b, head_a);
	}
}