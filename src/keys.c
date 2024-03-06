/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:59:26 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/06 19:01:54 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	iterations(int key, t_mlx *mlx_info)
{
	if (key == IPLUS)
		mlx_info->iter.value += 1;
	if (key == IMINUS && mlx_info->iter.value > 1)
		mlx_info->iter.value -= 1;
}

void	zoom(int key, t_mlx *mlx_info)
{
	if (key == ZOOM_IN)
		mlx_info->zoom.value *= 1.1;
	if (key == ZOOM_OUT)
		mlx_info->zoom.value /= 1.1;
}

void	movement(int key, t_mlx *mlx_info)
{
	if (key == W_UP || key == UP)
		mlx_info->zoom.y -= 15 / mlx_info->zoom.value;
	if (key == S_DOWN || key == DOWN)
		mlx_info->zoom.y += 15 / mlx_info->zoom.value;
	if (key == A_LEFT || key == LEFT)
		mlx_info->zoom.x -= 15 / mlx_info->zoom.value;
	if (key == D_RIGHT || key == RIGHT)
		mlx_info->zoom.x += 15 / mlx_info->zoom.value;
}

void	reset(int key, t_mlx *mlx_info)
{
	if (key == RESET)
	{
		mlx_info->iter.value = 20;
		mlx_info->zoom.value = 200;
		mlx_info->zoom.x = 0;
		mlx_info->zoom.y = 0;
	}
}

void	escape(int key)
{
	if (key == ESC)
		exit(0);
}
