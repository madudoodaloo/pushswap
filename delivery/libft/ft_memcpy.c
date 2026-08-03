/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 19:20:20 by masilva-          #+#    #+#             */
/*   Updated: 2026/04/15 19:20:20 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*cpy;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	source = (unsigned char *)src;
	cpy = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cpy[i] = source[i];
		i++;
	}
	return (dest);
}
