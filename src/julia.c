/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:59:46 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/14 16:59:01 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_loop(t_all *vars, float x, float y)
{
	int		i;
	float	x_new;

	i = 0;
	while (((x * x) + (y * y)) <= 4 && i < vars->fractol.iter)
	{
		x_new = (x * x) - (y * y) + vars->fractol.julia_r;
		y = (2 * x * y) + vars->fractol.julia_i;
		x = x_new;
		i++;
	}
	return (i);
}

void	julia_cycle(int col, int row, t_all *vars)
{
	float	c_re;
	float	c_im;

	c_re = (((float)col / (float)vars->fractol.width) * (vars->fractol.max_x - \
		vars->fractol.min_x)) + vars->fractol.min_x;
	c_im = (((float)row / (float)vars->fractol.height) * (vars->fractol.max_y - \
		vars->fractol.min_y)) + vars->fractol.min_y;
	color_grad(vars, julia_loop(vars, c_re, c_im), col, row);
}

void	julia(t_all *vars)
{
	int	x;
	int	y;

	vars->fractol.iter = 50 * log10(vars->fractol.zoom + 10);
	x = 0;
	while (x < vars->fractol.width)
	{
		y = 0;
		while (y < vars->fractol.height)
			julia_cycle(x, y++, vars);
		x++;
	}
}
