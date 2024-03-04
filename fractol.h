/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:09:10 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/04 02:07:27 by slegaris         ###   ########.fr       */
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

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define MAX_ITER 100
# define CENTER_REAL -0.75
# define CENTER_IMAG -0.75

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int t;
}	t_color;

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

// Colors //
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

// X //


#endif
