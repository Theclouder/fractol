/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:13:15 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/16 13:31:41 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	my_mlx_pixel_put(t_all *vars, int x, int y, int color)
//{
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_window(t_all *vars)
{
	vars->image.mlx = mlx_init();
	if (!vars->image.mlx)
		return (1);
	vars->image.win = mlx_new_window(vars->image.mlx, vars->fractol.width, \
		vars->fractol.height, vars->string);
	if (!vars->image.win)
		return (2);
	vars->image.img = mlx_new_image(vars->image.mlx, vars->fractol.width, \
		vars->fractol.height);
	if (!vars->image.img)
		return (3);
	vars->image.addr = mlx_get_data_addr(vars->image.img, \
			&vars->image.bits_per_pixel, \
			&vars->image.line_length, &vars->image.endian);
	if (!vars->image.addr)
		return (4);
	hook_mlx(vars);
	return (0);
}
