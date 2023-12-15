/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:01 by slegaris          #+#    #+#             */
/*   Updated: 2023/12/13 18:29:20 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>
#include <stdlib.h>


int calc_col(int iteration)
{
    int r, g, b;

    if (iteration == MAX_ITER)
        return create_trgb(0, 0, 0, 0);
    r = (iteration * 5) % 255;
    g = (iteration * 10) % 255;
    b = (iteration * 20) % 255;
    return create_trgb(0, r, g, b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

Complex map_pixel_to_complex(int x, int y, double zoom)
{
    Complex n;
    n.real = (x - WIN_WIDTH / 2.0) / zoom  + CENTER_REAL;
    n.imag = (y - WIN_HEIGHT / 2.0) / zoom  + CENTER_IMAG;
    return n;
}

int mandelbrot_iter(Complex c)
{
    int i;
    Complex z;
    double temp;

    z.real = 0;
    z.imag = 0;
    i = 0;
    while (i < MAX_ITER && z.real * z.real + z.imag * z.imag <= 4)
    {
        temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp;
        i++;
    }
    return i;
}

void draw_mandelbrot(t_img *img, double zoom)
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
	    c = map_pixel_to_complex(x, y, zoom);
	    color = mandelbrot_iter(c);
	    // printf("Color: %d\n", color);
	    my_mlx_pixel_put(img, x, y, calc_col(color));
	    x++;
	}
	y++;
    }
}

int keyhook(int keycode, t_img *img)
{
    int zoom;

    zoom = 500;
    if (keycode == 4)
    {
	zoom += 10;
	draw_mandelbrot(img, zoom);
    }
    if (keycode == 5)
    {
	zoom -= 10;
	draw_mandelbrot(img, zoom);
    }
    return 1;
}

int	main(void)
{
    void	*mlx;
    void	*mlx_win;
    t_img	img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
    img.img_ptr = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
    img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
							    &img.endian);
    draw_mandelbrot(&img, 500);
    mlx_mouse_hook(mlx_win, keyhook, &img);
    mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
    mlx_loop(mlx);
    return 0;
}
