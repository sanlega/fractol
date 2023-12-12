/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:12:16 by slegaris          #+#    #+#             */
/*   Updated: 2023/03/30 19:25:43 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nodo;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		nodo = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = nodo;
	}
	*lst = NULL;
}
