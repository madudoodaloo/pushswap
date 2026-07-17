/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 01:33:14 by masilva-          #+#    #+#             */
/*   Updated: 2026/06/28 01:33:14 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(char c, va_list args)
{
	if (c == 'c')
		pf_putchar(va_arg(args, int));
	else if (c == 's')
		pf_putstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		pf_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_putunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), 's');
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), 'b');
	else if (c == 'p')
		ft_putptr((unsigned long int)va_arg(args, void *));
	else if (c == '%')
		pf_putchar('%');
	return ;
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_convert(str[++i], args);
			if (!str[i])
				break ;
		}
		else
			pf_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (ft_count(-1));
}
