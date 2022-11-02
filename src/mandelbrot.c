/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:40:34 by vduchi              #+#  #+#             */
/*   Updated: 2022/10/29 20:18:56 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define VIOLET	0.8055
#define	BLUE	0.6111
#define	RED		0.9583
#define	GREEN	0.3888
#define	YELLOW	0.1388

int		*assign_rgb(float r, float g, float b)
{
	int	*rgb;

	rgb = (int *)malloc(sizeof(int) * 3);
	rgb[0] = (int)(r * 255);
	rgb[1] = (int)(g * 255);
	rgb[2] = (int)(b * 255);
	return (rgb);
}

int		*calculate_rgb(float h, float s, float v)
{
	int		*rgb;
	float	values[5];

	values[0] = floor(h * 6);
	values[1] = (h * 6) - values[0];
	values[2] = v * (1 - s);
	values[3] = v * (1 - (values[1] * s));
	values[4] = v * (1 - ((1 - values[1]) * s));
	if (((int)values[0] % 6) == 0)
		rgb = assign_rgb(v, values[4], values[2]);
	if (((int)values[0] % 6) == 1)
		rgb = assign_rgb(values[3], v, values[2]);
	if (((int)values[0] % 6) == 2)
		rgb = assign_rgb(values[2], v, values[4]);
	if (((int)values[0] % 6) == 3)
		rgb = assign_rgb(values[2], values[3], v);
	if (((int)values[0] % 6) == 4)
		rgb = assign_rgb(values[4], values[2], v);
	if (((int)values[0] % 6) == 5)
		rgb = assign_rgb(v, values[2], values[3]);
	return (rgb);
}

//int		calculate_colour()
//{
//}

void	color_gradient(t_all *vars, int i, int col, int row)
{
	int		*rgb;
//	int		sat;
	float	sat;

	sat = (float)i / (float)vars->fractol.iter;
	if (i < vars->fractol.iter)
	{
		if (vars->fractol.color == 0)
			rgb = calculate_rgb(VIOLET, 2 - (sat * 1.8), 1.0);
		else if (vars->fractol.color == 1)
			rgb = calculate_rgb(BLUE, sat * 0.8, 1.0);
		else if (vars->fractol.color == 2)
			rgb = calculate_rgb(RED, sat * 0.8, 1.0);
		else if (vars->fractol.color == 3)
			rgb = calculate_rgb(GREEN, sat * 0.8, 1.0);
		else if (vars->fractol.color == 4)
			rgb = calculate_rgb(YELLOW, sat * 0.8, 1.0);
		else
			rgb = calculate_rgb(sat, 1.0, 1.0);
	}
	else
		rgb = calculate_rgb(360, 1.0, 0.0);
	my_mlx_pixel_put(&vars->img, col, row, (((0 & 0xff) << 24) + ((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + ((rgb[2] & 0xff))));
	free(rgb);
}

int		loop(float c_re, float c_im, int iter)
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

	c_re = (((float)col / (float)vars->fractol.width) * (vars->fractol.max_x - vars->fractol.min_x)) + vars->fractol.min_x;
	c_im = (((float)row / (float)vars->fractol.height) * (vars->fractol.max_y - vars->fractol.min_y)) + vars->fractol.min_y;

	color_gradient(vars, loop(c_re, c_im,vars->fractol.iter), col, row);
//	if (loop(c_re, c_im, vars->fractol.iter) < vars->fractol.iter)
//		my_mlx_pixel_put(&vars->img, col, row, 0x00FFFFFF);
//	else
//		my_mlx_pixel_put(&vars->img, col, row, 0x00000000);
}

void	mandelbrot(t_all *vars)
{
	int	x;
	int	y;

//	vars->fractol.iter = 50 * pow(log10(vars->fractol.zoom + 10), 1.25);
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
