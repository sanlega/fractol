/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:43:11 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/06 18:53:58 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	zoomhook(int button, int x, int y, void *param)
{
	t_mlx		*mlx_info;
	t_complex	mouse_p;

	mlx_info = (t_mlx *)param;
	mouse_p = map_pixel_to_complex(x, y, *mlx_info);
	if (button == 1 && mlx_info->type.value == 1)
	{
		mlx_info->julia.real += mouse_p.real * 0.085;
		mlx_info->julia.imag += mouse_p.imag * 0.085;
	}
	if (button == MW_UP)
	{
		mlx_info->zoom.value *= 1.1;
		mlx_info->zoom.x += (mouse_p.real - mlx_info->zoom.x) * (1 - 1 / 1.1);
		mlx_info->zoom.y += (mouse_p.imag - mlx_info->zoom.y) * (1 - 1 / 1.1);
	}
	else if (button == MW_DOWN)
	{
		mlx_info->zoom.value /= 1.1;
		mlx_info->zoom.x -= (mouse_p.real - mlx_info->zoom.x) * (1 - 1.1);
		mlx_info->zoom.y -= (mouse_p.imag - mlx_info->zoom.y) * (1 - 1.1);
	}
	update_zoom_and_redraw(mlx_info, 0);
	return (0);
}

int	keyhook(int key, t_mlx *mlx_info)
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

void	endclose(t_mlx *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data, data->img.img_ptr);
	if (data->win)
		mlx_destroy_window(data->mlx_ptr, data->win);
	free(data->mlx_ptr);
	exit(0);
}

void	setup_hooks(t_mlx mlx_info)
{
	mlx_hook(mlx_info.win, ON_DESTROY, 0, (void *)endclose, &mlx_info);
	mlx_key_hook(mlx_info.win, keyhook, &mlx_info);
	mlx_mouse_hook(mlx_info.win, zoomhook, &mlx_info);
}
