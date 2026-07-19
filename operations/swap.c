#include "../push_swap.h"

void	sa(t_stack** head)
{
	int	temp;

	if(head && *head && (*head)->next)
	{
		temp = (*head)->next->n;
		(*head)->next->n = (*head)->n;
		(*head)->n = temp;
	}
}

void	sb(t_stack** head)
{
	sa(head);
}

void	ss(t_stack** head_a, t_stack **head_b)
{
	sa(head_a);
	sb(head_b);
}

//uma troca muito simples de números apenas usando uma variável tempirária para
//guardar o primeiro numero a ser metido lá
//guard o segundo numero numa coisa temporária 9
//dá o valor do primeiro numero ao segundo 10
//dá o valor da variável temporária ao primeiro 11

void	s_commands(t_stack** head_a, t_stack** head_b, char command, char stack)
{
	write(1, "s", 1);
	if(stack == 'a')
	{
		write(1, "a", 1);
		write(1, "\n", 1);
		sa(head_a);
	}
	if(stack == 'b')
	{
		write(1, "b", 1);
		write(1, "\n", 1);
		sb(head_b);
	}
	if(stack == 's')
	{
		write(1, "s", 1);
		write(1, "\n", 1);
		ss(head_a, head_b);
	}
}