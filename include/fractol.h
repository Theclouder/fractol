/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */ /*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:59:47 by vduchi            #+#    #+#             */
/*   Updated: 2022/10/10 16:56:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <fcntl.h>
# include <unistd.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"

typedef struct s_data {
	void  *img;
	char  *addr;
	int	  bits_per_pixel;
	int	  line_length;
	int	  endian;
}	t_data;

typedef struct	s_dtb {
	int		width;
	int		height;
	int		iter;
	int		color;
	int 	status;
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

typedef struct s_all {
	void	*win;
	void	*mlx;
	t_data	img;
	t_dtb	fractol;
	char	type;
}	t_all;

int	loop_hook(t_all *vars);
int	create_window(t_all *vars);
int	clear_all(t_all *vars, char *str);
int	key_hook(int keycode, t_all *vars);
int	close_window(int keycode, t_all *vars);
int	atof_julia(const char *str, t_all *vars, int mod);
int	mouse_hook(int button, int x, int y, t_all *vars);

void	julia(t_all *vars);
void	hook_mlx(t_all *vars);
void	free_vars(t_all *vars);
void	mandelbrot(t_all *vars);
void	init_array(t_all *vars);
void	color_grad(t_all *vars, int i, int col, int row);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
