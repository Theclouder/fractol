/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:22:11 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/12 00:10:23 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clear_all(t_all *vars, char *str)
{
	if (str)
		ft_printf(str);
	if (vars->mlx)
		free(vars->mlx);
	printf("%p\n%p\n", vars, vars->mlx);
//	if (vars->img.addr)
//	{
//		ft_printf("1\n");
//		free(vars->img.addr);
//		vars->img.addr = NULL;
//	}
//	if (vars->img.img)
//	{
//		ft_printf("2\n");
//		free(vars->img.img);
//		vars->img.img = NULL;
//	}
//	if (vars->win)
//	{
//		ft_printf("3\n");
//		free(vars->win);
//		vars->win = NULL;
//	}
//	if (vars->mlx)
//	{
//		ft_printf("4\n");
//		free(vars->mlx);
//		vars->mlx = NULL;
//	}
	return (0);
}

void	hook_mlx(t_all *vars)
{
	if (vars->type == 'M')
		mandelbrot(vars);
	else if (vars->type == 'J')
		julia(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, close_window, &vars);
	mlx_loop_hook(vars->mlx, loop_hook, vars);
	mlx_loop(vars->mlx);
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
}
