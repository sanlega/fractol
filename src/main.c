/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:01 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/08 06:06:14 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"
#include <sys/wait.h>
#include <unistd.h>

t_complex	map_pixel_to_complex(int x, int y, t_mlx mlx_info)
{
	t_complex	n;

	n.real = ((x - WIN_WIDTH / 2.0) / mlx_info.zoom.value) + mlx_info.zoom.x;
	n.imag = ((y - WIN_HEIGHT / 2.0) / mlx_info.zoom.value) + mlx_info.zoom.y;
	return (n);
}

void	update_zoom_and_redraw(t_mlx *mlx_info, int delta)
{
	if (delta)
		mlx_info->zoom.value += delta;
	if (mlx_info->type.value == 0)
		draw_mandelbrot(&mlx_info->img, *mlx_info);
	if (mlx_info->type.value == 1)
		draw_julia(&mlx_info->img, mlx_info);
	if (mlx_info->mlx_ptr && mlx_info->win && mlx_info->img.img_ptr)
	{
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win,
			mlx_info->img.img_ptr, 0, 0);
	}
	else
	{
		printf("Error\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx_info;

	checkargs(ac, av, &mlx_info);
	setup_mlx(&mlx_info);
	defsetup(&mlx_info);
	setup_hooks(&mlx_info);
	if (mlx_info.type.value == 0)
		draw_mandelbrot(&mlx_info.img, mlx_info);
	if (mlx_info.type.value == 1)
		draw_julia(&mlx_info.img, &mlx_info);
	mlx_put_image_to_window(mlx_info.mlx_ptr, mlx_info.win,
		mlx_info.img.img_ptr, 0, 0);
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}
