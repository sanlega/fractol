/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:01 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/05 17:53:25 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

t_complex map_pixel_to_complex(int x, int y, t_mlx mlx_info)
{
    t_complex n;
    n.real = ((x - WIN_WIDTH / 2.0) / mlx_info.zoom.value)  + mlx_info.zoom.x;
    n.imag = ((y - WIN_HEIGHT / 2.0) / mlx_info.zoom.value)  + mlx_info.zoom.y;
    return (n);
}

void update_zoom_and_redraw(t_mlx *mlx_info, int delta)
{
    mlx_info->zoom.value += delta;
    if (mlx_info->type.value == 0)
	draw_mandelbrot(&mlx_info->img, *mlx_info);
    if (mlx_info->type.value == 1)
	draw_julia(&mlx_info->img, mlx_info);
    mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win,			// ABORT EN ESTA LINEA
		    mlx_info->img.img_ptr, 0, 0);
}

int	main(void)
{
    t_mlx	mlx_info;

    mlx_info.type.value = 1;

    setup_mlx(&mlx_info);
    defsetup(&mlx_info);
    setup_hooks(mlx_info);
    if (mlx_info.type.value == 0)
	draw_mandelbrot(&mlx_info.img, mlx_info);
    if (mlx_info.type.value == 1)
	draw_julia(&mlx_info.img, &mlx_info);
    mlx_put_image_to_window(mlx_info.mlx_ptr, mlx_info.win, mlx_info.img.img_ptr, 0, 0);
    mlx_loop(mlx_info.mlx_ptr);

    return (0);
}
