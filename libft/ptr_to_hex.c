/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:43:56 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/17 00:46:43 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ptr_to_hex(void *ptr, char *str)
{
	const char		*hex_chars;
	unsigned long	addr;
	int				i;

	hex_chars = "0123456789abcdef";
	addr = (unsigned long)ptr;
	i = sizeof(ptr) * 2 - 1;
	while (i >= 0)
	{
		str[i] = hex_chars[addr & 0xF];
		addr >>= 4;
		i--;
	}
	str[sizeof(ptr) * 2] = '\0';
}
