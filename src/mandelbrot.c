/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:40:34 by vduchi              #+#  #+#             */
/*   Updated: 2022/11/13 22:46:05 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_loop(float c_re, float c_im, int iter)
{
	int		i;
	float	x;
	float	y;
	float	x_new;

	i = 0;
	x = 0.0;
	y = 0.0;
	while (((x * x) + (y * y)) <= 4 && i < iter)
	{
		x_new = (x * x) - (y * y) + c_re;
		y = (2 * x * y) + c_im;
		x = x_new;
		i++;
	}
	return (i);
}

void	man_cycle(int col, int row, t_all *vars)
{
	float	c_re;
	float	c_im;

	c_re = (((float)col / (float)vars->fractol.width) * (vars->fractol.max_x - \
		vars->fractol.min_x)) + vars->fractol.min_x;
	c_im = (((float)row / (float)vars->fractol.height) * (vars->fractol.max_y - \
		vars->fractol.min_y)) + vars->fractol.min_y;
	color_grad(vars, mandelbrot_loop(c_re, c_im, vars->fractol.iter), col, row);
}

void	mandelbrot(t_all *vars)
{
	int	x;
	int	y;

	vars->fractol.iter = 50 * log10(vars->fractol.zoom + 10);
	x = 0;
	while (x < vars->fractol.width)
	{
		y = 0;
		while (y < vars->fractol.height)
			man_cycle(x, y++, vars);
		x++;
	}
}
