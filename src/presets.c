/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:58:20 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 23:10:47 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	colors(int key, t_mlx *mlx_info)
{
	color1(key, mlx_info);		
	color2(key, mlx_info);		
	color3(key, mlx_info);		
	color4(key, mlx_info);		
	color5(key, mlx_info);		
}
