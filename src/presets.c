/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:58:20 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/05 14:34:57 by slegaris         ###   ########.fr       */
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

int calc_col(int iteration, t_mlx mlx_info)
{
    int r;
    int g;
    int b;
    
    if (iteration == mlx_info.iter.value) // Color del centro
        return create_trgb(0, mlx_info.palette.mainR, mlx_info.palette.mainG,
			   mlx_info.palette.mainB);
    r = (iteration * mlx_info.palette.r) % 255;
    g = (iteration * mlx_info.palette.g) % 255;
    b = (iteration * mlx_info.palette.b) % 255;
    return (create_trgb(0, r, g, b));
}
