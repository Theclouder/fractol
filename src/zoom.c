/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:13:56 by vduchi            #+#    #+#             */
/*   Updated: 2022/10/29 16:06:12 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_all *vars)
{
//	float	new_min_x;
//	float	new_min_y;
//	float	new_max_x;
//	float	new_max_y;

	if (button == 5)
	{
		vars->fractol.zoom *= 1.25;
		vars->fractol.min_x += (((float)x / 8.0 * (float)(vars->fractol.max_x - vars->fractol.min_x)) / (float)vars->fractol.width);
		vars->fractol.min_y += (((float)y / 8.0 * (float)(vars->fractol.max_y - vars->fractol.min_y)) / (float)vars->fractol.height);
		vars->fractol.max_x -= ((((float)vars->fractol.width - (float)x) / 8.0 * (float)(vars->fractol.max_x - vars->fractol.min_x)) / (float)vars->fractol.width);
		vars->fractol.max_y -= ((((float)vars->fractol.height - (float)y) / 8.0 * (float)(vars->fractol.max_y - vars->fractol.min_y)) / (float)vars->fractol.height);
	}
	else if (button == 4)
	{
		vars->fractol.zoom /= 1.25;
		vars->fractol.min_x -= (((float)x / 8.0 * (float)(vars->fractol.max_x - vars->fractol.min_x)) / (float)vars->fractol.width);
		vars->fractol.min_y -= (((float)y / 8.0 * (float)(vars->fractol.max_y - vars->fractol.min_y)) / (float)vars->fractol.height);
		vars->fractol.max_x += ((((float)vars->fractol.width - (float)x) / 8.0 * (float)(vars->fractol.max_x - vars->fractol.min_x)) / (float)vars->fractol.width);
		vars->fractol.max_y += ((((float)vars->fractol.height - (float)y) / 8.0 * (float)(vars->fractol.max_y - vars->fractol.min_y)) / (float)vars->fractol.height);
	}
	free(vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, vars->fractol.width, vars->fractol.height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
//	vars->fractol.x_mouse = ((x - 640) / (320 * vars->fractol.zoom)) - ((x - 640) / (320 * new_zoom)) + vars->fractol.x_mouse;
//	vars->fractol.y_mouse = ((y - 640) / (320 * vars->fractol.zoom)) - ((y - 640) / (320 * new_zoom)) + vars->fractol.y_mouse;
//	new_min_x = ((x * (vars->fractol.max_x - vars->fractol.min_x)) / vars->fractol.width) - vars->fractol.max_x;
//	vars->fractol.min_x += (((float)x / 5.0) / (float)vars->fractol.width);
//	vars->fractol.min_y += (((float)y / 5.0) / (float)vars->fractol.height);
//	vars->fractol.max_x -= ((((float)vars->fractol.width - (float)x) / 5.0) / (float)vars->fractol.width);
//	vars->fractol.min_y -= ((((float)vars->fractol.height - (float)y) / 5.0) / (float)vars->fractol.height);
	printf("Min X: %f\nMin Y: %f\nMax X: %f\nMax Y: %f\nZoom: %f\n\n", vars->fractol.min_x, vars->fractol.min_y, \
			vars->fractol.max_x, vars->fractol.max_y, vars->fractol.zoom);
//	vars->fractol.left_right += vars->fractol.x_mouse / vars->fractol.zoom;
//	vars->fractol.up_down += vars->fractol.y_mouse / vars->fractol.zoom;
	vars->fractol.status = 1;
	return (0);
}
