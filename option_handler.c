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
	static int strat;

	if (info == 'i')
		return (bench * 10 + strat);
	if (!bench && !ft_strncmp(option, BENCH, 8))
		bench++;
	else if (!strat && !ft_strncmp(option, SIMPLE, 9))
		strat += 1;
	else if (!strat && !ft_strncmp(option, MEDIUM, 9))
		strat += 2;
	else if (!strat && !ft_strncmp(option, COMPLEX, 10))
		strat += 3;
	else if (!strat && !ft_strncmp(option, ADAPTIVE, 11))
		strat += 4;
	else
		return (-1);
	return (0);
}
