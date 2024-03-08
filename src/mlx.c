/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:36:39 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/08 06:06:22 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	setup_mlx(t_mlx *mlx_info)
{
	mlx_info->mlx_ptr = mlx_init();
	mlx_info->win = mlx_new_window(mlx_info->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "Mandelbrot Set");
	mlx_info->img.img_ptr = mlx_new_image(mlx_info->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT);
	mlx_info->img.data = mlx_get_data_addr(mlx_info->img.img_ptr,
			&mlx_info->img.bpp,
			&mlx_info->img.size_l,
			&mlx_info->img.endian);
}
