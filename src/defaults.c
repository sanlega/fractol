/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:24:37 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 19:42:59 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	defpallete(t_mlx *mlx_info)
{
	mlx_info->palette.r = 15;
	mlx_info->palette.g = 0;
	mlx_info->palette.b = 10;
}
