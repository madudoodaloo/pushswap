#include "../push_swap.h"

//raiz quadrada adaptado a inteiros
int	pitagoras(int n)
{
    int i = 0;
    while (i * i < n)
        i++;
    return (i);
}

//calcula o numero minimo existente no subgrupo
int chunk_boundary(t_stack** head, int chunk)
{
	int	length;
	int	min;
	int	max;
	int	range;

	length = get_length(head);
	min = lowest_with_floor(head, 0, 0);
	max = highest_with_cieling(head, 0, 0);
	range = (max - min) + 1;
	return (min + ((chunk * range) / pitagoras(length)));
}

//encontra todos os elementos do subgrupo no stack A e puxa-os para o B
void push_chunk(t_stack** head_a, t_stack** head_b,int chunk)
{
	int i;
	int length;
	int chunk_min;
	int chunk_max;

	i = 0;
	length = get_length(head_a);
	chunk_min = chunk_boundary(head_a, chunk);
	chunk_max = chunk_boundary(head_a, (chunk + 1));
	while(i < length)
	{
		if((chunk_min <= (*head_a)->n) && ((*head_a)->n < chunk_max))
		{
			commands(head_a, head_b, 'p', 'b');
		}
		else
			commands(head_a, head_b, 'r', 'a');
		i++;
	}
}

void medium_algorithm(t_stack** head_a, t_stack** head_b)
{
	int length;
	int chunk;
	int highest;

	length = get_length(head_a);
	chunk = pitagoras(length) - 1;
	while(chunk >= 0)
	{
		push_chunk(head_a, head_b, chunk);
		while(*head_b)
		{
			highest = highest_with_cieling(head_b, 0, 0);
			while((*head_b)->n != highest)
				faster_way(head_b, highest, 'b');
			commands(head_a, head_b, 'p', 'a');
		}
		chunk--;
	}
}
