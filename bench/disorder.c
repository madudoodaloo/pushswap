/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 03:54:53 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/12 03:54:53 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	compute_disorder(t_stack **a)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*curr;
	t_stack	*temp;

	mistakes = 0;
	total_pairs = 0;
	curr = *a;
	while (curr)
	{
		temp = curr->next;
		while (temp)
		{
			total_pairs++;
			if (curr->n > temp->n)
				mistakes++;
			temp = temp->next;
		}
		curr = curr->next;
	}
	if (!total_pairs)
		return (0.0f);
	return (((float)mistakes / (float)total_pairs) * 100.0f);
}
