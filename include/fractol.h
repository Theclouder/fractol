/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:16:16 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/16 15:45:11 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <string.h>

# include <fcntl.h>
# include <unistd.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"

/*	---		Structure for the mlx and the image values		---  */
typedef struct s_data {
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
}	t_data;

/*  ---		Structure for all the values of the fractals	---  */
typedef struct s_dtb {
	int		width;
	int		height;
	int		iter;
	int		color;
	int		status;
	float	max_x;
	float	min_x;
	float	max_y;
	float	min_y;
	float	x_mouse;
	float	y_mouse;
	float	up_down;
	float	left_right;
	float	zoom;
	float	julia_r;
	float	julia_i;
}		t_dtb;

/*  ---		General structure containing all variables		---  */
typedef struct s_all {
	char	type;
	char	*string;
	t_data	image;
	t_dtb	fractol;
}	t_all;

/*  ---		Hooks.c		---  */
int		loop_hook(t_all *vars);
int		key_hook(int keycode, t_all *vars);
int		mouse_hook(int button, int x, int y, t_all *vars);

/*  ---		Window.c	---  */
int		create_window(t_all *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//void	my_mlx_pixel_put(t_all *vars, int x, int y, int color);

/*  ---		Atof_julia.c	---  */
int		atof_julia(const char *str, t_all *vars, int mod);

/*  ---		Utils.c		---  */
void	error_msg(int index);
void	hook_mlx(t_all *vars);
void	init_array(t_all *vars);
int		clear_all(t_all *vars, int res);
int		exit_safe(t_all *vars, int index);

/*  ---		Zoom.c		---  */
void	zoom_in(t_all *vars, int x, int y);
void	zoom_out(t_all *vars, int x, int y);

/*  ---		Julia.c		---  */
void	julia(t_all *vars);

/*  ---		Mandelbrot.c	---  */
void	mandelbrot(t_all *vars);

/*  ---		Burning_Ship.c	---  */
void	burning_ship(t_all *vars);

/*  ---		Colour.c		---  */
void	color_grad(t_all *vars, int i, int col, int row);

#endif
