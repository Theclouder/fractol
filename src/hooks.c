/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:29:45 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/11 23:36:59 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(int keycode, t_all *vars)
{
	(void)vars;
	keycode = 0;
	printf("Exited by closing the window!\n");
	exit(0);
}

void	second_key_hook(int keycode, t_all *vars)
{
	float	change;

	if (keycode == 124)
	{
		vars->fractol.status = 1;
		change = (vars->fractol.max_x - vars->fractol.min_x) / 20;
		vars->fractol.min_x += change;
		vars->fractol.max_x += change;
	}
	else if (keycode == 125)
	{
		vars->fractol.status = 1;
		change = (vars->fractol.max_y - vars->fractol.min_y) / 20;
		vars->fractol.min_y += change;
		vars->fractol.max_y += change;
	}
	else if (keycode == 126)
	{
		vars->fractol.status = 1;
		change = (vars->fractol.max_y - vars->fractol.min_y) / 20;
		vars->fractol.min_y -= change;
		vars->fractol.max_y -= change;
	}
}

int	key_hook(int keycode, t_all *vars)
{
	float	change;

	if (keycode == 53)
	{
		ft_printf("Exited by pressing ESC!\n");
		exit(0);
	}
	else if (keycode == 8)
	{
		vars->fractol.status = 1;
		if (vars->fractol.color == 5)
			vars->fractol.color = 0;
		else
			vars->fractol.color = vars->fractol.color + 1;
	}
	else if (keycode == 123)
	{
		vars->fractol.status = 1;
		change = (vars->fractol.max_x - vars->fractol.min_x) / 20;
		vars->fractol.min_x -= change;
		vars->fractol.max_x -= change;
	}
	else
		second_key_hook(keycode, vars);
	return (0);
}

int	loop_hook(t_all *vars)
{
	if (vars->fractol.status == 1)
	{
		vars->fractol.status = 0;
		if (vars->type == 'M')
			mandelbrot(vars);
		else if (vars->type == 'J')
			julia(vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (1);
}
