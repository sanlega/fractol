/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:24:37 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 22:34:06 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	defpallete(t_mlx *mlx_info)
{
	mlx_info->palette.r = 15;
	mlx_info->palette.g = 0;
	mlx_info->palette.b = 10;
	mlx_info->palette.mainR = 50;
	mlx_info->palette.mainG = 0;
	mlx_info->palette.mainB = 50;
}

void	defiter(t_mlx *mlx_info)
{
	mlx_info->iter.value = 20;
}

void	defzoom(t_mlx *mlx_info)
{
	mlx_info->zoom.value = 200;
}

void	defsetup(t_mlx *mlx_info)
{
    defpallete(mlx_info);
    defzoom(mlx_info);
    defiter(mlx_info);
}
