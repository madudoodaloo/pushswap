#include "../push_swap.h"


void	commands(t_stack** head_a, t_stack** head_b, char command, char stack)
{
	if(command == 's')
		s_commands(head_a, head_b, stack);
	else if(command == 'p')
		p_commands(head_a, head_b, stack);
	else if(command == 'r')
		r_commands(head_a, head_b, stack);
	else if(command == 'd')
		rr_commands(head_a, head_b, stack);
}
