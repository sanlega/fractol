/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:01 by slegaris          #+#    #+#             */
/*   Updated: 2023/12/13 16:07:21 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	// printf("Color: %i\n", color);
	// printf("x : %i, y: %i\n", x, y);
	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		x;
	int		y;
	int		color = create_trgb(0, 255, 255, 0);

	x = 0;
	y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	img.img_ptr = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
								&img.endian);
	while(y < WIN_WIDTH)
	{
		while(x < WIN_HEIGHT - 1)
		{
			// mlx_pixel_put(mlx, mlx_win, x, y, color);
			my_mlx_pixel_put(&img, x, y, color);
			x++;
			// printf("x : %i, y: %i\n", x, y);
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	mlx_loop(mlx);
	return 0;
}
