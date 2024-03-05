/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:01 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/05 14:53:16 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

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
    draw_mandelbrot(&mlx_info->img, *mlx_info);
    mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win, mlx_info->img.img_ptr, 0, 0);
}

int	main(void)
{
    t_mlx	mlx_info;

    setup_mlx(&mlx_info);
    defsetup(&mlx_info);

    mlx_hook(mlx_info.win, 17, 0, &on_destroy, &mlx_info);
    mlx_hook(mlx_info.win, 4, 0, zoomhook, &mlx_info);
    mlx_key_hook(mlx_info.win, keyhook, &mlx_info);
    draw_mandelbrot(&mlx_info.img, mlx_info);
    mlx_put_image_to_window(mlx_info.mlx_ptr, mlx_info.win, mlx_info.img.img_ptr, 0, 0);
    mlx_loop(mlx_info.mlx_ptr);

    return (0);
}
