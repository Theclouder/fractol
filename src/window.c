/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:13:15 by vduchi            #+#    #+#             */
/*   Updated: 2022/10/29 20:07:13 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
//	else if (keycode == 69)
//	{
//		vars->fractol.status = 1;
//		vars->fractol.iter += 10;
//	}
//	else if (keycode == 78)
//	{
//		vars->fractol.status = 1;
//		vars->fractol.iter -= 10;
//	}
	else if (keycode == 123)
	{
		vars->fractol.status = 1;
		change = (vars->fractol.max_x - vars->fractol.min_x) / 20;
		vars->fractol.min_x -= change;
		vars->fractol.max_x -= change; 
	}
	else if (keycode == 124)
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
	printf("Keycode: %d\n", keycode);
	return (0);
}

int	close_window(int keycode, t_all *vars)
{
	(void)vars;
	keycode = 0;
	printf("Exited by closing the window!\n");
	exit(0);
}

int	loop_hook(t_all *vars)
{
	if (vars->fractol.status == 1)
	{
		vars->fractol.status = 0;
		mandelbrot(vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (1);
}

//mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );

int	create_window(t_all *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		perror("Malloc failed!");
		return (0);
	}
	vars->win = mlx_new_window(vars->mlx, vars->fractol.width, vars->fractol.height, "Mandelbrot");
	vars->img.img = mlx_new_image(vars->mlx, vars->fractol.width, vars->fractol.height);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
			&vars->img.bits_per_pixel, \
			&vars->img.line_length, &vars->img.endian);
//	full_the_screen(vars, 1920, 1080);
//	my_mlx_pixel_put(&vars->img, 5, 5, 0x00FF0000);
	mandelbrot(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
//	mlx_destroy_image(vars->mlx, vars->img.img);
//	mlx_loop_hook(vars->mlx, NULL, &vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
//	mlx_hook(vars->win, 4, 0, zoom_out, vars);
//	mlx_hook(vars->win, 5, 0, zoom_in, &vars);
	mlx_hook(vars->win, 17, 0, close_window, &vars);
	mlx_loop_hook(vars->mlx, loop_hook, vars);
	mlx_loop(vars->mlx);
	return (1);
}
