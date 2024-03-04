/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:01 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 23:19:43 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int calc_col(int iteration, t_mlx mlx_info)
{
    int r;
    int g;
    int b;
    
    if (iteration == mlx_info.iter.value) // Color del centro
        return create_trgb(0, mlx_info.palette.mainR, mlx_info.palette.mainG,
			   mlx_info.palette.mainB);
    r = (iteration * mlx_info.palette.r) % 255;
    g = (iteration * mlx_info.palette.g) % 255;
    b = (iteration * mlx_info.palette.b) % 255;
    return (create_trgb(0, r, g, b));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	dst = img->data + (y * img->size_l + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

Complex map_pixel_to_complex(int x, int y, t_mlx mlx_info)
{
    Complex n;
    n.real = ((x - WIN_WIDTH / 2.0) / mlx_info.zoom.value)  + mlx_info.zoom.x;
    n.imag = ((y - WIN_HEIGHT / 2.0) / mlx_info.zoom.value)  + mlx_info.zoom.y;
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

void draw_mandelbrot(t_img *img, t_mlx mlx_info)
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
	    c = map_pixel_to_complex(x, y, mlx_info);
	    color = mandelbrot_iter(c, mlx_info.iter.value);
	    my_mlx_pixel_put(img, x, y, calc_col(color, mlx_info));
	    x++;
	}
	y++;
    }
}

void update_zoom_and_redraw(t_mlx *mlx_info, int delta)
{
    mlx_info->zoom.value += delta;
    draw_mandelbrot(&mlx_info->img, *mlx_info);
    mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win, mlx_info->img.img_ptr, 0, 0);
}


int zoomhook(int button, int x, int y, void *param)
{
    t_mlx *mlx_info = (t_mlx *)param;
    Complex mouse_point = map_pixel_to_complex(x, y, *mlx_info);

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

int	main(void)
{
    t_mlx	mlx_info;

    mlx_info.mlx_ptr = mlx_init();
    mlx_info.win = mlx_new_window(mlx_info.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Mandelbrot Set");
    mlx_info.img.img_ptr = mlx_new_image(mlx_info.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    mlx_info.img.data = mlx_get_data_addr(mlx_info.img.img_ptr, &mlx_info.img.bpp, &mlx_info.img.size_l, &mlx_info.img.endian);

    defsetup(&mlx_info);
    mlx_hook(mlx_info.win, 17, 0, &on_destroy, &mlx_info);
    mlx_hook(mlx_info.win, 4, 0, zoomhook, &mlx_info);
    mlx_key_hook(mlx_info.win, keyhook, &mlx_info);
    draw_mandelbrot(&mlx_info.img, mlx_info);
    mlx_put_image_to_window(mlx_info.mlx_ptr, mlx_info.win, mlx_info.img.img_ptr, 0, 0);
    mlx_loop(mlx_info.mlx_ptr);

    return (0);
}
