/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:11:16 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 18:24:50 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	next_hash(unsigned long current_hash)
{
	current_hash = current_hash * 6269667103370058243UL + 1;
	return (current_hash);
}

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

unsigned long	harder_hash(unsigned long hash)
{
	void			*ptr;
	char			*str;
	int				i;
	unsigned long	new_hash;

	ptr = malloc(1);
	str = (char *)malloc(256);
	if (!ptr || !str)
	{
		if (ptr)
			free(ptr);
		if (str)
			free(str);
		exit(1);
	}
	ptr_to_hex(ptr, str);
	i = 0;
	new_hash = hash;
	while (str[i])
	{
		new_hash = ((new_hash << 5) + new_hash) + str[i];
		i++;
	}
	return (free(ptr), free(str), new_hash);
}

unsigned long	simple_hash(void)
{
	unsigned long	hash;
	void			*ptr;
	char			*str;
	int				i;

	ptr = malloc(1);
	str = (char *)malloc(256);
	if (!ptr || !str)
	{
		if (ptr)
			free(ptr);
		if (str)
			free(str);
		exit(1);
	}
	ptr_to_hex(ptr, str);
	i = 0;
	hash = 3674298;
	while (str[i])
	{
		hash = ((hash << 5) + hash) + str[i];
		i++;
	}
	return (free(ptr), free(str), harder_hash(hash));
}

int	ft_rand(int min, int max)
{
	unsigned long	hash;
	int				output;
	int				range;
	unsigned long	rand_val;

	hash = simple_hash();
	range = max - min + 1;
	rand_val = next_hash(hash);
	output = (int)(rand_val % range) + min;
	return (output);
}
