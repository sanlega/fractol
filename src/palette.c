/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:09:18 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/06 19:22:45 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	color1(int key, t_mlx *mlx_info)
{
	if (key == 18)
	{
		mlx_info->palette.r = 15;
		mlx_info->palette.g = 10;
		mlx_info->palette.b = 0;
		mlx_info->palette.main_r = 50;
		mlx_info->palette.main_g = 60;
		mlx_info->palette.main_b = 0;
	}
}

void	color2(int key, t_mlx *mlx_info)
{
	if (key == 19)
	{
		mlx_info->palette.r = 0;
		mlx_info->palette.g = 10;
		mlx_info->palette.b = 15;
		mlx_info->palette.main_r = 0;
		mlx_info->palette.main_g = 25;
		mlx_info->palette.main_b = 50;
	}
}

void	color3(int key, t_mlx *mlx_info)
{
	if (key == 20)
	{
		mlx_info->palette.r = 15;
		mlx_info->palette.g = 5;
		mlx_info->palette.b = 10;
		mlx_info->palette.main_r = 200;
		mlx_info->palette.main_g = 200;
		mlx_info->palette.main_b = 200;
	}
}

void	color4(int key, t_mlx *mlx_info)
{
	if (key == 21)
	{
		mlx_info->palette.r = 10;
		mlx_info->palette.g = 10;
		mlx_info->palette.b = 10;
		mlx_info->palette.main_r = 100;
		mlx_info->palette.main_g = 100;
		mlx_info->palette.main_b = 100;
	}
}

void	color5(int key, t_mlx *mlx_info)
{
	if (key == 29)
	{
		mlx_info->palette.r = 15;
		mlx_info->palette.g = 0;
		mlx_info->palette.b = 10;
		mlx_info->palette.main_r = 50;
		mlx_info->palette.main_g = 0;
		mlx_info->palette.main_b = 50;
	}
}
