/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:22:11 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/16 13:31:38 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_safe(t_all *vars, int index)
{
	if (!index)
		ft_printf("Exit with ESC!\n");
	else
		ft_printf("Exit with the cross!\n");
	clear_all(vars, 0);
	return (0);
}

int	clear_all(t_all *vars, int index)
{
	error_msg(index - 1);
	if (vars->image.mlx && vars->image.img)
	{
		mlx_destroy_image(vars->image.mlx, vars->image.img);
	}
	if (vars->image.mlx && vars->image.win)
		mlx_destroy_window(vars->image.mlx, vars->image.win);
	exit(0);
}

void	error_msg(int index)
{
	if (index == 0)
		ft_printf("Malloc failed!\n");
	if (index == 1)
		ft_printf("Window creation failed!\n");
	if (index == 2)
		ft_printf("Image creation failed!\n");
	if (index == 3)
		ft_printf("Address not set correctly!\n");
	if (index == 4)
		ft_printf("Wrong number of arguments!\n");
	if (index == 5)
		ft_printf("Wrong arguments!\n");
	if (index == 6)
		ft_printf("One of the arguments is not a number!\n");
	if (index == 7)
		ft_printf("One of the arguments is more than 2 or less than -2\n");
}

void	hook_mlx(t_all *vars)
{
	if (vars->type == 'M')
		mandelbrot(vars);
	else if (vars->type == 'J')
		julia(vars);
	else if (vars->type == 'B')
		burning_ship(vars);
	mlx_put_image_to_window(vars->image.mlx, vars->image.win, \
		vars->image.img, 0, 0);
	vars->fractol.status = 0;
	mlx_key_hook(vars->image.win, key_hook, vars);
	mlx_mouse_hook(vars->image.win, mouse_hook, vars);
	mlx_hook(vars->image.win, 17, 0, exit_safe, vars);
	mlx_loop_hook(vars->image.mlx, loop_hook, vars);
	mlx_loop(vars->image.mlx);
}

void	init_array(t_all *vars)
{
	vars->fractol.width = 1281;
	vars->fractol.height = 1281;
	vars->fractol.max_x = 2.0;
	vars->fractol.min_x = -2.0;
	vars->fractol.max_y = 2.0;
	vars->fractol.min_y = -2.0;
	vars->fractol.x_mouse = 0.0;
	vars->fractol.y_mouse = 0.0;
	vars->fractol.up_down = 0.0;
	vars->fractol.left_right = 0.0;
	vars->fractol.zoom = 1.0;
	vars->fractol.iter = 50;
	vars->fractol.color = 0;
	vars->fractol.status = 1;
	vars->fractol.julia_r = 0.0;
	vars->fractol.julia_i = 0.0;
	vars->image.mlx = NULL;
	vars->image.win = NULL;
	vars->image.img = NULL;
	vars->image.addr = NULL;
	vars->string = NULL;
}
