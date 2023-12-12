/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:17:07 by slegaris          #+#    #+#             */
/*   Updated: 2023/03/29 20:38:26 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = (t_list *)malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}
//
// int main(void)
// {
// 	t_list *new_node;
// 	int content = 42;
//
// 	new_node = ft_lstnew(&content);
// 	if (new_node == NULL)
// 	{
// 		printf("Error: no se ha podido reservar memoria para el nuevo nodo.\n");
// 		return (1);
// 	}
//
// 	printf("Nueo nodo creado con el contenido: 
//		%d\n", *((int *)new_node->content));
// 	
// 	free(new_node);
// 	return (0);
// }
