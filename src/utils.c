/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:50:30 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/05 17:17:13 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void update_zoom_and_redraw(t_mlx *mlx_info, int delta)
{
    mlx_info->zoom.value += delta;
    // draw_mandelbrot(&mlx_info->img, *mlx_info);
    draw_julia(&mlx_info->img, mlx_info);
    mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win,
				mlx_info->img.img_ptr, 0, 0);
}
