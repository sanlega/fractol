/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:09:10 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 23:10:22 by slegaris         ###   ########.fr       */
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


typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int t;
}	t_color;

typedef struct s_palette
{
	int r;
	int g;
	int b;
	int mainR;
	int mainG;
	int mainB;
}	t_palette;

typedef struct s_iter 
{
	int	defaultval;
	int	value;
}	t_iter;

typedef struct s_zoom
{
	double	value;
	int	delta;
	double	x;
	double	y;
}	t_zoom;

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_zoom		zoom;
	t_iter		iter;
	t_palette	palette;
}				t_mlx;

typedef struct {
    double real;
    double imag;
} Complex;


typedef struct s_fractol
{
    t_mlx	mlx;
    t_zoom	zoom;
}				t_fractol;

// Functions //
void	defsetup(t_mlx *mlx_info);
void	iterations(int key, t_mlx *mlx_info);
void	zoom(int key, t_mlx *mlx_info);
void	movement(int key, t_mlx *mlx_info);
void	reset(int key, t_mlx *mlx_info);
void	escape(int key);
void	colors(int key, t_mlx *mlx_info);
void	color1(int key, t_mlx *mlx_info);
void	color2(int key, t_mlx *mlx_info);
void	color3(int key, t_mlx *mlx_info);
void	color4(int key, t_mlx *mlx_info);
void	color5(int key, t_mlx *mlx_info);

// Colors //
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

// X //


#endif
