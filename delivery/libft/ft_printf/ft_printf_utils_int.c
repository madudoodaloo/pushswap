/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 05:43:44 by masilva-          #+#    #+#             */
/*   Updated: 2026/06/28 05:43:44 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putnbr(int n)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		pf_putchar('-');
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		pf_putchar(nbr + 48);
		return ;
	}
	pf_putnbr(nbr / 10);
	pf_putnbr(nbr % 10);
}

void	ft_putunsigned(unsigned int nbr)
{
	if (nbr < 10)
	{
		pf_putchar(nbr + 48);
		return ;
	}
	ft_putunsigned(nbr / 10);
	ft_putunsigned(nbr % 10);
}

void	ft_puthex(unsigned long int nbr, int c)
{
	char	*str;

	if (c == 's')
		str = S_HEX;
	else
		str = B_HEX;
	if (nbr < 16)
	{
		pf_putchar(str[nbr]);
		return ;
	}
	ft_puthex(nbr / 16, c);
	pf_putchar(str[nbr % 16]);
}

void	ft_putptr(unsigned long int nbr)
{
	if (!nbr)
	{
		pf_putstr("(nil)");
		return ;
	}
	pf_putstr("0x");
	ft_puthex(nbr, 's');
}
