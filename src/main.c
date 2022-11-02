/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:08:54 by vduchi            #+#    #+#             */
/*   Updated: 2022/10/29 20:01:11 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int check_args(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Put a map name in the command line:\n\t1. J (for Julia)\n\t\
2. M (for Mandelbrot)\n");
		return (0);
	}
	else if (argc >= 3)
	{
		ft_printf("Too many arguments, it is only needed the map file name\n");
		return (0);
	}
	else if (!ft_strncmp(argv[1], "J", 1))
		return (1);
	else if (!ft_strncmp(argv[1], "M", 1))
		return (2);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_all vars;

	vars.fractol.width = 1281;
	vars.fractol.height = 1281;
	vars.fractol.max_x = 2.0;
	vars.fractol.min_x = -2.0;
	vars.fractol.max_y = 2.0;
	vars.fractol.min_y = -2.0;
	vars.fractol.x_mouse = 0.0;
	vars.fractol.y_mouse = 0.0;
	vars.fractol.up_down = 0.0;
	vars.fractol.left_right = 0.0;
	vars.fractol.zoom = 1.0;
	vars.fractol.iter = 50;
	vars.fractol.color = 0;
	vars.fractol.status = 1;
	if (!check_args(argc, argv))
		return (0);
	if (!create_window(&vars))
		return (0);
	return (0);
}
