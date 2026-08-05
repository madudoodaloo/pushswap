/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 05:31:06 by masilva-          #+#    #+#             */
/*   Updated: 2026/08/05 05:31:06 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_neighbours(t_stack *s, int range)
{
	if (ft_lstsize(s) < range)
		range = ft_lstsize(s);
	
}

void	set_index(t_stack **s)
{
	t_stack	*temp;
	t_stack	*cursor;

	cursor = *s;
	while (cursor)
	{
		cursor->index = 0;
		temp = *s;
		while (temp)
		{
			if (cursor != temp && cursor->content > temp->content)
				cursor->index++;
			temp = temp->next;
		}
		cursor = cursor->next;
	}
}

// returns 1 if element is closer to the top,
// returns -1 if element is closer to the bottom,

int	get_cost(t_stack **s, int target_index, int size)
{
	int		i;
	t_stack	*cursor;

	i = 0;
	cursor = *s;
	while (cursor->index != target_index)
	{
		i++;
		cursor = cursor->next;
	}
	size = size - i;
	if (i < size)
		return (1);
	return (-1);
}

int	get_biggestindex(t_stack **stack)
{
	t_stack	*cursor;
	int		big_ind;

	cursor = *stack;
	big_ind = cursor->index;
	while (cursor)
	{
		if (cursor->index > big_ind)
			big_ind = cursor->index;
		cursor = cursor->next;
	}
	return (big_ind);
}
