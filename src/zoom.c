/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:13:56 by vduchi            #+#    #+#             */
/*   Updated: 2022/10/11 16:30:29 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_all *vars)
{
	float new_zoom;
	if (button == 5)
		new_zoom = vars->fractol.zoom * 1.25;
	else if (button == 4 && vars->fractol.zoom > 0.0)
		new_zoom = vars->fractol.zoom / 1.25;
	else
		return (0);
	vars->img.img = mlx_new_image(vars->mlx, vars->fractol.max_x, vars->fractol.max_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->fractol.x_mouse = ((x - 640) / (320 * vars->fractol.zoom)) - ((x - 640) / (320 * new_zoom)) + vars->fractol.x_mouse;
	vars->fractol.y_mouse = ((y - 640) / (320 * vars->fractol.zoom)) - ((y - 640) / (320 * new_zoom)) + vars->fractol.y_mouse;
	vars->fractol.zoom = new_zoom;
	printf("X: %f\nY: %f\nZoom: %f\nLeft_Right: %f\nUp_Down: %f\n", vars->fractol.x_mouse, vars->fractol.y_mouse, \
			vars->fractol.zoom, vars->fractol.left_right, vars->fractol.up_down);
	vars->fractol.status = 1;
	return (0);
}
