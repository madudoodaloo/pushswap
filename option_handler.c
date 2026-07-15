/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 03:49:37 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/15 03:49:37 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getoptions(char *option, char info)
{
	static int bench;
	static int strategy;

	if (info == 'i')
		;
	if (!bench && !ft_strcmp(option, BENCH))
		bench++;
	else if (!strat && !ft_strcmp(option, SIMPLE))
		strategy += 1;
	else if (!strat && !ft_strcmp(option, MEDIUM))
		strategy += 2;
	else if (!strat && !ft_strcmp(option, COMPLEX))
		strategy += 3;
	else if (!strat && !ft_strcmp(option, ADAPTIVE))
		strategy += 4;
	else
		return (-1)
	return (bench * 10 + strategy);
}
