/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:43:11 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/05 15:05:51 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


int zoomhook(int button, int x, int y, void *param)
{
    t_mlx *mlx_info = (t_mlx *)param;
    t_complex mouse_point = map_pixel_to_complex(x, y, *mlx_info);

    if (button == MW_UP)
    {
        mlx_info->zoom.value *= 1.1;
        mlx_info->zoom.x += (mouse_point.real - mlx_info->zoom.x) * (1 - 1 / 1.1);
        mlx_info->zoom.y += (mouse_point.imag - mlx_info->zoom.y) * (1 - 1 / 1.1);
    }
    else if (button == MW_DOWN)
    {
        mlx_info->zoom.value /= 1.1;
        mlx_info->zoom.x -= (mouse_point.real - mlx_info->zoom.x) * (1 - 1.1);
        mlx_info->zoom.y -= (mouse_point.imag - mlx_info->zoom.y) * (1 - 1.1);
    }
    update_zoom_and_redraw(mlx_info, 0);
    return (0);
}

int keyhook(int key, t_mlx *mlx_info)
{
    iterations(key, mlx_info);
    zoom(key, mlx_info);
    movement(key, mlx_info);
    colors(key, mlx_info);
    reset(key, mlx_info);
    escape(key);
    update_zoom_and_redraw(mlx_info, 0);
    return (0);
}

int on_destroy(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	setup_hooks(t_mlx mlx_info)
{
    mlx_hook(mlx_info.win, 17, 0, &on_destroy, &mlx_info);
    mlx_hook(mlx_info.win, 4, 0, zoomhook, &mlx_info);
    mlx_key_hook(mlx_info.win, keyhook, &mlx_info);
}
