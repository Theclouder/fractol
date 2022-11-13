/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:03:18 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/11 23:08:59 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define VIOLET	0.8055
#define BLUE	0.6111
#define RED		0.9583
#define GREEN	0.3888
#define YELLOW	0.1388

int	*assign_rgb(float r, float g, float b)
{
	int	*rgb;

	rgb = (int *)malloc(sizeof(int) * 3);
	rgb[0] = (int)(r * 255);
	rgb[1] = (int)(g * 255);
	rgb[2] = (int)(b * 255);
	return (rgb);
}

float	hue2rgb(float p, float q, float t)
{
	if (t < 0.0)
		t += 1.0;
	if (t > 1.0)
		t -= 1.0;
	if (t < 0.1667)
		return (p + ((q - p) * 6.0 * t));
	if (t < 0.5)
		return (q);
	if (t < 0.6777)
		return (p + ((q - p) * (0.6777 - t) * t));
	return (p);
}

int	*hsl_to_rgb(float h, float s, float l)
{
	int		*rgb;
	float	values[5];

	if (s == 0)
		rgb = assign_rgb(l, l, l);
	else
	{
		if (l < 0.5)
			values[0] = l * (1 + s);
		else
			values[0] = l + s - (l * s);
		values[1] = (2 * l) - values[0];
		values[2] = hue2rgb(values[1], values[0], h + 0.3333);
		values[3] = hue2rgb(values[1], values[0], h);
		values[4] = hue2rgb(values[1], values[0], h - 0.3333);
		rgb = assign_rgb(values[2], values[3], values[4]);
	}
	return (rgb);
}

int	*hsv_to_rgb(float h, float s, float v)
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

void	color_grad(t_all *vars, int i, int col, int row)
{
	int		*rgb;
	float	light;

	light = (float)i / (float)vars->fractol.iter;
	if (i < vars->fractol.iter)
	{
		if (vars->fractol.color == 0)
			rgb = hsl_to_rgb(VIOLET, 1.0, light);
		else if (vars->fractol.color == 1)
			rgb = hsl_to_rgb(BLUE, 1.0, light);
		else if (vars->fractol.color == 2)
			rgb = hsl_to_rgb(RED, 1.0, light);
		else if (vars->fractol.color == 3)
			rgb = hsl_to_rgb(GREEN, 1.0, light);
		else if (vars->fractol.color == 4)
			rgb = hsl_to_rgb(YELLOW, 1.0, light);
		else
			rgb = hsv_to_rgb(light, 1.0, 1.0);
	}
	else
		rgb = hsv_to_rgb(360, 1.0, 0.0);
	my_mlx_pixel_put(&vars->img, col, row, (((0 & 0xff) << 24) + \
		((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + ((rgb[2] & 0xff))));
	free(rgb);
}
