/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:09:10 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/08 06:06:18 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include "mlx/mlx.h"
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 100
# define CENTER_REAL -0.75
# define CENTER_IMAG -0.75

// KEY's MACROS

# define ESC 53
# define RESET 15
# define IPLUS 34
# define IMINUS 31
# define MW_UP 4
# define MW_DOWN 5
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define W_UP 13
# define S_DOWN 1
# define A_LEFT 0
# define D_RIGHT 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ON_DESTROY 17

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}		t_color;

typedef struct s_palette
{
	int	r;
	int	g;
	int	b;
	int	main_r;
	int	main_g;
	int	main_b;
}		t_palette;

typedef struct s_iter
{
	int	defaultval;
	int	value;
}		t_iter;

typedef struct s_zoom
{
	double	value;
	int		delta;
	double	x;
	double	y;
}			t_zoom;

typedef struct s_type
{
	int	value;
}		t_type;

typedef struct s_img
{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_zoom		zoom;
	t_iter		iter;
	t_palette	palette;
	t_type		type;
	t_complex	julia;
}				t_mlx;

typedef struct s_fractol
{
	t_mlx	mlx;
	t_zoom	zoom;
}			t_fractol;

// Functions //
void		defsetup(t_mlx *mlx_info);
void		iterations(int key, t_mlx *mlx_info);
void		zoom(int key, t_mlx *mlx_info);
void		movement(int key, t_mlx *mlx_info);
void		reset(int key, t_mlx *mlx_info);
void		escape(int key);
void		setup_mlx(t_mlx *mlx_info);
void		setup_hooks(t_mlx *mlx_info);
int			zoomhook(int button, int x, int y, void *param);
int			keyhook(int key, t_mlx *mlx_info);
void		endclose(t_mlx *data);
void		update_zoom_and_redraw(t_mlx *mlx_info, int delta);
t_complex	map_pixel_to_complex(int x, int y, t_mlx mlx_info);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		draw_mandelbrot(t_img *img, t_mlx mlx_info);
int			mandelbrot_iter(t_complex c, int maxiter);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		draw_julia(t_img *img, t_mlx *mlx_info);
int			julia_iter(double x, double y, int maxiter, t_complex c);
void		checkargs(int ac, char **av, t_mlx *mlx_info);
void		def_complex(t_mlx *mlx_info);

// Colors //
int			calc_col(int iteration, t_mlx mlx_info);
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
void		colors(int key, t_mlx *mlx_info);
void		color1(int key, t_mlx *mlx_info);
void		color2(int key, t_mlx *mlx_info);
void		color3(int key, t_mlx *mlx_info);
void		color4(int key, t_mlx *mlx_info);
void		color5(int key, t_mlx *mlx_info);

// X //

#endif
