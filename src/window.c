/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:13:15 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/12 00:03:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	initialize_mlx(t_all *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx)
		return (clear_all(vars, "Malloc failed!\n"));
	if (vars->type == 'M')
		vars->win = mlx_new_window(vars->mlx, vars->fractol.width, \
			vars->fractol.height, "Mandelbrot");
	else if (vars->type == 'J')
		vars->win = mlx_new_window(vars->mlx, vars->fractol.width, \
			vars->fractol.height, "Julia");
	if (!vars->win)
		return (clear_all(vars, "Window creation failed!\n"));
	vars->img.img = mlx_new_image(vars->mlx, vars->fractol.width, \
		vars->fractol.height);
	if (!vars->img.img)
		return (clear_all(vars, "Image not created!\n"));
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
			&vars->img.bits_per_pixel, \
			&vars->img.line_length, &vars->img.endian);
	if (vars->img.addr)
		return (clear_all(vars, "Address not set correctly!\n"));
	hook_mlx(vars);
	return (1);
}

int	create_window(t_all *vars)
{
	if (!initialize_mlx(vars))
		return (0);
	return (1);
}
