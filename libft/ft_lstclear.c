/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masilva- <masilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:58:07 by masilva-          #+#    #+#             */
/*   Updated: 2026/04/21 19:58:07 by masilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iter;

	if (!del || !lst)
		return ;
	while (*lst != NULL)
	{
		iter = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = iter;
	}
	*lst = NULL;
}
