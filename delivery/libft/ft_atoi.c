/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:57:05 by masilva-          #+#    #+#             */
/*   Updated: 2026/04/16 18:57:05 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Standard C library  */
/* #include <stdlib.h> */

static int	ft_isspace(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return (uc == 32 || (uc >= 9 && uc <= 13));
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		nbr;
	size_t	i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
