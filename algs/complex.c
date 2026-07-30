#include "../push_swap.h"

//conta o numero de bits (codigo binario) de um numero (excluiu sinal negativo)
int number_of_bits(int number)
{
	int bits;
	int num;

	num = number;
	bits = 0;
	while(num != 0)
	{
		num = num / 2;
		bits++;
	}
	return (bits);
}

//procura pelo numero maximo de bits que o algoritmo tera de comparar
int find_bits(t_stack** head)
{
	int		bits;
	int		neg;
	t_stack*	node;

	node = *head;
	bits = number_of_bits(node->number);
	neg = 0;
	while(node)
	{
		if (bits < number_of_bits(node->number))
			bits = number_of_bits(node->number);
		node = node->next;
	}
	return (bits);
}

//o numero sofre uma ajuste para a direita em codigo binario (LRS) e depois e comparado com 1 numa operacao AND o que o que quer dizer que so podera retornar 1 ou 0
int	check_bit(int number, int bit)
{
	return ((number >> bit) & 1);
}

//esta funao procura os numeros negativos no stack e coloca-os abaio dos numeros positivos
void revert(t_stack** head_a, t_stack** head_b)
{
	int length;
	int i;
	int check;
	t_stack* node;

	length = get_length(head_a);
	i = 0;
	check = 0;
	node = *head_a;
	while(node)
	{
		if(node->number < 0)
			check++;
		node = node->next;
	}
	while((i < length) && (check != 0))
	{
		if((*head_a)->number < 0)
			commands(head_a, head_b, 'p', 'b');
		else
			commands(head_a, head_b, 'r', 'a');
		i++;
	}
	while(*head_b)
		commands(head_a, head_b, 'p', 'a');
}

void complex_algorithm(t_4stack** head_a, t_4stack** head_b)
{
	int bits;
	int bit;
	int length;
	int i;

	bits = find_bits(head_a);
	bit = 0;
	length = get_length(head_a);
	while(bit < bits)
	{
		i = 0;
		while(i < length)
		{
			if (check_bit((*head_a)->number, bit) == 0)
				commands(head_a, head_b, 'p', 'b');
			else
				commands(head_a, head_b, 'r', 'a');
			i++;
		}
		while(*head_b)
			commands(head_a, head_b, 'p', 'a');
		bit++;
	}
	revert(head_a, head_b);
}
