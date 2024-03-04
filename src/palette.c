/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:09:18 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 23:18:23 by slegaris         ###   ########.fr       */
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
		mlx_info->palette.mainR = 50;
		mlx_info->palette.mainG = 60;
		mlx_info->palette.mainB = 0;
	}
}

void	color2(int key, t_mlx *mlx_info)
{
	if (key == 19)
	{
		mlx_info->palette.r = 0;
		mlx_info->palette.g = 10;
		mlx_info->palette.b = 15;
		mlx_info->palette.mainR = 0;
		mlx_info->palette.mainG = 25;
		mlx_info->palette.mainB = 50;
	}
}

void	color3(int key, t_mlx *mlx_info)
{
	if (key == 20)
	{
		mlx_info->palette.r = 0;
		mlx_info->palette.g = 5;
		mlx_info->palette.b = 5;
		mlx_info->palette.mainR = 0;
		mlx_info->palette.mainG = 50;
		mlx_info->palette.mainB = 70;
	}
}

void	color4(int key, t_mlx *mlx_info)
{
	if (key == 21)
	{
		mlx_info->palette.r = 10;
		mlx_info->palette.g = 10;
		mlx_info->palette.b = 10;
		mlx_info->palette.mainR = 100;
		mlx_info->palette.mainG = 100;
		mlx_info->palette.mainB = 100;
	}
}

void	color5(int key, t_mlx *mlx_info)
{
	if (key == 29)
	{
		mlx_info->palette.r = 15;
		mlx_info->palette.g = 0;
		mlx_info->palette.b = 10;
		mlx_info->palette.mainR = 50;
		mlx_info->palette.mainG = 0;
		mlx_info->palette.mainB = 50;
	}
}
