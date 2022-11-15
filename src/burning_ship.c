/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:48 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/15 20:28:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	bs_loop(float c_re, float c_im, int iter)
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
		y = (2 * fabs(x) * fabs(y)) + c_im;
		x = x_new;
		i++;
	}
	return (i);
}

void	bs_cycle(int col, int row, t_all *vars)
{
	float	c_re;
	float	c_im;

	c_re = (((float)col / (float)vars->fractol.width) * (vars->fractol.max_x - \
		vars->fractol.min_x)) + vars->fractol.min_x;
	c_im = (((float)row / (float)vars->fractol.height) * (vars->fractol.max_y - \
		vars->fractol.min_y)) + vars->fractol.min_y;
	color_grad(vars, bs_loop(c_re, c_im, vars->fractol.iter), col, row);
}

void	burning_ship(t_all *vars)
{
	int	x;
	int	y;

	x = 0;
	vars->fractol.iter = 50 * log10(vars->fractol.zoom + 10);
	while (x < vars->fractol.width)
	{
		y = 0;
		while (y < vars->fractol.height)
			bs_cycle(x, y++, vars);
		x++;
	}
}
