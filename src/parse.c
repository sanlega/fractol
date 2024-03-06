/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:35:30 by slegaris          #+#    #+#             */
/*   Updated: 2024/03/06 19:07:30 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

void	ft_error(void)
{
	ft_printf("BAD INPUT.\n");
	ft_printf("Please select one of the following:\n");
	ft_printf("./fractol Mandelbrot\n");
	ft_printf("./fractol Julia <x.x> <x.x>\n");
	exit(0);
}

void	parse_doubles(char *arg1, char *arg2, t_mlx *mlx_info)
{
	double	d1;
	double	d2;

	d1 = ft_atof(arg1);
	d2 = ft_atof(arg2);
	if (!d1 || !d2)
		ft_error();
	else
	{
		mlx_info->julia.imag = d1;
		mlx_info->julia.real = d2;
	}
}

void	checkargs(int ac, char **av, t_mlx *mlx_info)
{
	if (ac > 1 && ac <= 4)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
		{
			mlx_info->type.value = 0;
		}
		else if (ft_strcmp(av[1], "Julia") == 0)
		{
			mlx_info->type.value = 1;
			if (ac > 2)
				parse_doubles(av[2], av[3], mlx_info);
			else
				def_complex(mlx_info);
		}
		else
			ft_error();
	}
	else
		ft_error();
}
