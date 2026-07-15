/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:47:41 by masilva-          #+#    #+#             */
/*   Updated: 2026/04/16 17:47:41 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Utility functions from BSD systems (libbsd, -lbsd) */
/* #include <bsd/string.h> */
/* max_byte adds 1 to make sure last expected byte is inspected */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned char	*bigger;
	unsigned char	*smaller;
	size_t			i;
	size_t			t;

	bigger = (unsigned char *)big;
	smaller = (unsigned char *)little;
	i = 0;
	if (*smaller == '\0')
		return ((char *)big);
	while (bigger[i] && i < len)
	{
		t = 0;
		while (bigger[i + t] == smaller[t] && (i + t) < len)
		{
			t++;
			if (smaller[t] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
