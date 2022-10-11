/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
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
	int	max_x;
	int	max_y;
	int	iter;
	int	status;
	float x_mouse;
	float y_mouse;
	float up_down;
	float left_right;
	float zoom;
}	t_dtb;

typedef struct s_all {
	void	*win;
	void	*mlx;
	t_data	img;
	t_dtb	fractol;
}	t_all;

void  free_vars(t_all *vars);

int	create_window(t_all *vars);

void  mandelbrot(t_all *vars);
void  my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	mouse_hook(int button, int x, int y, t_all *vars);

#endif