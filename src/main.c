/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:01 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 17:18:31 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>
#include <stdlib.h>

int calc_col(int iteration, int maxiter)
{
    int r, g, b;

    if (iteration == maxiter)
        return create_trgb(0, 0, 0, 0);
    r = (iteration * 5) % 255;
    g = (iteration * 10) % 255;
    b = (iteration * 20) % 255;
    return (create_trgb(0, r, g, b));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

Complex map_pixel_to_complex(int x, int y, t_zoom zoom, t_zoom center)
{
    Complex n;
    n.real = ((x - WIN_WIDTH / 2.0) / zoom.value)  + center.x;
    n.imag = ((y - WIN_HEIGHT / 2.0) / zoom.value)  + center.y;
    return (n);
}

int mandelbrot_iter(Complex c, int maxiter)
{
    int i;
    Complex z;
    double temp;

    z.real = 0;
    z.imag = 0;
    i = 0;
    while (i < maxiter && z.real * z.real + z.imag * z.imag <= 4)
    {
        temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp;
        i++;
    }
    return (i);
}

void draw_mandelbrot(t_img *img, t_zoom zoom, t_zoom center, t_iter iter)
{
    int	    x;
    int	    y;
    int	    color;
    Complex c;

    y = 0;
    while (y < WIN_HEIGHT)
    {
	x = 0;
	while (x < WIN_WIDTH)
	{
	    c = map_pixel_to_complex(x, y, zoom, center);
	    color = mandelbrot_iter(c, iter.value);
	    my_mlx_pixel_put(img, x, y, calc_col(color, iter.value));
	    x++;
	}
	y++;
    }
}

void update_zoom_and_redraw(t_mlx *mlx_info, int delta)
{
    mlx_info->zoom.value += delta;
    draw_mandelbrot(&mlx_info->img, mlx_info->zoom, mlx_info->zoom, mlx_info->iter);
    mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win, mlx_info->img.img_ptr, 0, 0);
}


int zoomhook(int button, int x, int y, void *param)
{
    t_mlx *mlx_info = (t_mlx *)param;

    Complex mouse_point = map_pixel_to_complex(x, y, mlx_info->zoom, mlx_info->zoom);

    printf("mousecode: %d\n", button);
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
    if (button == 17)
	exit(0);
    return (0);
}

int keyhook(int key, t_mlx *mlx_info)
{
    printf("Key: %d\n", key);

    if (key == IPLUS)
	mlx_info->iter.value += 1;
    if (key == IMINUS && mlx_info->iter.value > 1)
	mlx_info->iter.value -= 1;
    if (key == ZOOM_IN)
    {
        mlx_info->zoom.value *= 1.1;
    }
    if (key == ZOOM_OUT)
    {
        mlx_info->zoom.value /= 1.1;
    }
    if (key == UP)
    {
	mlx_info->zoom.y -= 15 / mlx_info->zoom.value;
    }
    if (key == DOWN)
    {
	mlx_info->zoom.y += 15 / mlx_info->zoom.value;
    }
    if (key == LEFT)
    {
	mlx_info->zoom.x -= 15 / mlx_info->zoom.value;
    }
    if (key == RIGHT)
    {
	mlx_info->zoom.x += 15 / mlx_info->zoom.value;
    }
    update_zoom_and_redraw(mlx_info, 0);
    if (key == RESET)
    {
	mlx_info->iter.value = 20;
	mlx_info->zoom.value = 200;
	mlx_info->zoom.x = 0;
	mlx_info->zoom.y = 0;
	update_zoom_and_redraw(mlx_info, 0);
    }
    if (key == ESC)
    {
	exit(0);
    }

    printf("Iters: %d\n", mlx_info->iter.value);

    return (0);
}

int on_destroy(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	main(void)
{
    t_mlx	mlx_info;

    mlx_info.mlx_ptr = mlx_init();
    mlx_info.win = mlx_new_window(mlx_info.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Mandelbrot Set");
    mlx_info.img.img_ptr = mlx_new_image(mlx_info.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    mlx_info.img.data = mlx_get_data_addr(mlx_info.img.img_ptr, &mlx_info.img.bpp, &mlx_info.img.size_l, &mlx_info.img.endian);

    mlx_info.zoom.value = 200;
    mlx_info.zoom.x = 0;
    mlx_info.zoom.y = 0;
    mlx_info.iter.value = 20;

    mlx_hook(mlx_info.win, 4, 0, zoomhook, &mlx_info);
    mlx_key_hook(mlx_info.win, keyhook, &mlx_info);
    draw_mandelbrot(&mlx_info.img, mlx_info.zoom, mlx_info.zoom, mlx_info.iter);
    mlx_put_image_to_window(mlx_info.mlx_ptr, mlx_info.win, mlx_info.img.img_ptr, 0, 0);
    mlx_hook(mlx_info.win, 17, 0, &on_destroy, &mlx_info);
    mlx_loop(mlx_info.mlx_ptr);

    return (0);
}
