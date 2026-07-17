/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:46:29 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/17 17:46:29 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *performance_benchmark(int elements, int total_moves)
{
	if (elements <= 100 && total_moves < 700)
		return ("Excellent!");
	else if (elements <= 100 && total_moves < 1500)
		return ("Good");
	else if (elements <= 100 && total_moves < 700)
		return ("Minimum");
	else if (elements <= 500 && total_moves < 5500)
		return ("Excellent!");
	else if (elements <= 500 && total_moves < 8000)
		return ("Good");
	else if (elements <= 500 && total_moves < 12000)
		return ("Minimum");
	else
		return ("N/A");
}