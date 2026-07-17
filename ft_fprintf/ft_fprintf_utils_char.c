/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 05:43:18 by masilva-          #+#    #+#             */
/*   Updated: 2026/06/28 05:43:18 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

// -1, in case of write() error
// -2, to reset the count variable between function calls
int	fpf_count(int printed)
{
	static int	count;
	int			total;

	if (printed == -2)
	{
		total = count;
		count = 0;
		return (total);
	}
	if (printed == -1)
		return (-1);
	count += printed;
	return (count);
}

void	fpf_putchar(int fd, char c)
{
	fpf_count(write(fd, &c, 1));
}

void	fpf_putstr(int fd, char *str)
{
	if (!str)
		str = "(null)";
	fpf_count(write(fd, str, ft_strlen(str)));
}
