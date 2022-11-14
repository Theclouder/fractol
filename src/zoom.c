/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:13:56 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/14 09:59:44 by vduchi           ###   ########.fr       */
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
