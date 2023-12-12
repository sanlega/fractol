/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:01 by slegaris          #+#    #+#             */
/*   Updated: 2023/12/12 20:46:29 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

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
//	int		color = create_trgb(255, 255, 255, 0);

	x = 200;
	y = 200;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1001, 1001, "Hello world!");
	img.img_ptr = mlx_new_image(mlx, 1001, 1001);
	img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
								&img.endian);
	while(y < 400 )
	{
		while(x < 400)
		{
			my_mlx_pixel_put(&img, x, y, 0xFFFF0000);
			x++;
			// printf("x : %i, y: %i\n", x, y);
		}
		y++;
		x = 200;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	mlx_loop(mlx);
	return 0;
}
