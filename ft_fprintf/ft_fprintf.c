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

#include "ft_fprintf.h"

void	fpf_convert(int fd, char c, va_list args)
{
	if (c == 'c')
		fpf_putchar(fd, va_arg(args, int));
	else if (c == 's')
		fpf_putstr(fd, va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		fpf_putnbr(fd, va_arg(args, int));
	else if (c == 'u')
		fpf_putunsigned(fd, va_arg(args, unsigned int));
	else if (c == 'x')
		fpf_puthex(fd, va_arg(args, unsigned int), 's');
	else if (c == 'X')
		fpf_puthex(fd, va_arg(args, unsigned int), 'b');
	else if (c == 'p')
		fpf_putptr(fd, (unsigned long int)va_arg(args, void *));
	else if (c == '%')
		fpf_putchar(fd, '%');
	return ;
}

int    ft_fprintf(int fd, const char *str, ...)
{
	size_t		i;
	va_list 	args;

	i = 0;
	va_start(args, str);
	if (fd < 0 || !str)
		return (-1);
	while (str[i] && ft_count(0) != -1)
	{
		if (str[i] == '%')
		{
			fpf_convert(fd, str[++i], args);
			if (!str[i])
				break ;
		}
		else
			fpf_putchar(fd, str[i]);
		i++;
	}
	va_end(args);
	return (ft_count(-2));
}
