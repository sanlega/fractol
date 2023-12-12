/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:10:10 by slegaris          #+#    #+#             */
/*   Updated: 2023/10/12 17:11:11 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n, int sign)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (sign == -1)
		++len;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
