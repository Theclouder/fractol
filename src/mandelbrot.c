/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:40:34 by vduchi              #+#  #+#             */
/*   Updated: 2022/10/10 17:56:23 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	  loop(float c_re, float c_im, int iter)
{
	int	  i;
	float x;
	float y;
	float x_new;

	i = 0;
	x = 0;
	y = 0;
	while (((x * x) + (y * y)) <= 4 && i < iter)
	{
		x_new = (x * x) - (y * y) + c_re;
		y = (2 * x * y) + c_im;
		x = x_new;
		i++;
	}
	return (i);
}

void  man_cycle(int col, int row, t_all *vars)
{
	float c_re;
	float c_im;

	if (vars->fractol.x_mouse < 0.0)
		c_re = (col - 640) / (320 * vars->fractol.zoom) + vars->fractol.x_mouse - vars->fractol.left_right;
	else
		c_re = (col - 640) / (320 * vars->fractol.zoom) + vars->fractol.x_mouse + vars->fractol.left_right;
	if (vars->fractol.y_mouse < 0.0)
		c_im = (row - 640) / (320 * vars->fractol.zoom) + vars->fractol.y_mouse - vars->fractol.up_down;
	else
		c_im = (row - 640) / (320 * vars->fractol.zoom) + vars->fractol.y_mouse + vars->fractol.up_down;
	if (loop(c_re, c_im, vars->fractol.iter) < vars->fractol.iter)
		my_mlx_pixel_put(&vars->img, col, row, 0x00FFFFFF);
	else
		my_mlx_pixel_put(&vars->img, col, row, 0x00000000);
}

void  mandelbrot(t_all *vars)
{
	int	x;
	int	y;

//	vars->fractol.iter = 50 * pow(log10(vars->fractol.zoom + 10), 1.25);
	x = 0;
	while (x < vars->fractol.max_x)
	{
		y = 0;
		while (y < vars->fractol.max_y)
			man_cycle(x, y++, vars);
		x++;
	}
}
