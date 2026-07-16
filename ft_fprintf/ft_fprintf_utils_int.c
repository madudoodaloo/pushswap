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

#include "ft_fprintf.h"

void	fpf_putnbr(int fd, int n)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		fpf_putchar(fd, '-');
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		fpf_putchar(fd, nbr + 48);
		return ;
	}
	fpf_putnbr(fd, nbr / 10);
	fpf_putnbr(fd, nbr % 10);
}

void	fpf_putunsigned(int fd, unsigned int nbr)
{
	if (nbr < 10)
	{
		fpf_putchar(fd, nbr + 48);
		return ;
	}
	fpf_putunsigned(fd, nbr / 10);
	fpf_putunsigned(fd, nbr % 10);
}


void	fpf_puthex(int fd, unsigned long int nbr, int c)
{
	char	*str;

	if (c == 's')
		str = S_HEX;
	else
		str = B_HEX;
	if (nbr < 16)
	{
		fpf_putchar(fd, str[nbr]);
		return ;
	}
	fpf_puthex(fd, nbr / 16, c);
	fpf_putchar(fd, str[nbr % 16]);
}

void	fpf_putptr(int fd, unsigned long int nbr)
{
	if (!nbr)
	{
		fpf_putstr(fd, "(nil)");
		return ;
	}
	fpf_putstr(fd, "0x");
	fpf_puthex(fd, nbr, 's');
}
