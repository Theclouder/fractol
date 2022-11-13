/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:13:56 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/11 23:52:35 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_all *vars, int x, int y)
{
	vars->fractol.zoom *= 1.25;
	vars->fractol.min_x += (((float)x / 8.0 * (float)(vars->fractol.max_x - \
		vars->fractol.min_x)) / (float)vars->fractol.width);
	vars->fractol.min_y += (((float)y / 8.0 * (float)(vars->fractol.max_y - \
		vars->fractol.min_y)) / (float)vars->fractol.height);
	vars->fractol.max_x -= ((((float)vars->fractol.width - (float)x) / 8.0 * \
		(float)(vars->fractol.max_x - vars->fractol.min_x)) / \
		(float)vars->fractol.width);
	vars->fractol.max_y -= ((((float)vars->fractol.height - (float)y) / 8.0 * \
		(float)(vars->fractol.max_y - vars->fractol.min_y)) / \
		(float)vars->fractol.height);
}

void	zoom_out(t_all *vars, int x, int y)
{
	vars->fractol.zoom /= 1.25;
	vars->fractol.min_x -= (((float)x / 8.0 * (float)(vars->fractol.max_x - \
		vars->fractol.min_x)) / (float)vars->fractol.width);
	vars->fractol.min_y -= (((float)y / 8.0 * (float)(vars->fractol.max_y - \
		vars->fractol.min_y)) / (float)vars->fractol.height);
	vars->fractol.max_x += ((((float)vars->fractol.width - (float)x) / 8.0 * \
		(float)(vars->fractol.max_x - vars->fractol.min_x)) / \
		(float)vars->fractol.width);
	vars->fractol.max_y += ((((float)vars->fractol.height - (float)y) / 8.0 * \
		(float)(vars->fractol.max_y - vars->fractol.min_y)) / \
		(float)vars->fractol.height);
}

int	mouse_hook(int button, int x, int y, t_all *vars)
{
	if (button == 5)
		zoom_in(vars, x, y);
	else if (button == 4)
		zoom_out(vars, x, y);
	free(vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, vars->fractol.width, \
		vars->fractol.height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->fractol.status = 1;
	return (0);
}
