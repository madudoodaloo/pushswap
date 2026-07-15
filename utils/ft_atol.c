/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 04:10:36 by masilva-          #+#    #+#             */
/*   Updated: 2026/07/15 04:10:36 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	ft_atol(char *str)
{
	size_t	i;
	size_t	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}
