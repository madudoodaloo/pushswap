/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 03:56:29 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/15 03:56:29 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_matrix(char **matrix)
{
	while (matrix)
	{
		if (*matrix)
			free(*matrix);
		*matrix++;
	}
	free(matrix);
}
