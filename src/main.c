/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:08:54 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/13 23:26:12 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	print_help(int index)
{
	if (index != 0)
		error_msg(index);
	ft_printf("You have to put one of these arguments:\n\t1. J (for Julia) ");
	ft_printf("+ z_re + z_im (Both values must be between 2.0 and -2.0)\n");
	ft_printf("\t2. M (for Mandelbrot)\n");
	return (0);
}

int	check_julia_par(char **argv, t_all *vars)
{
	if (argv[2] == NULL)
	{
		vars->fractol.julia_r = 0.285;
		vars->fractol.julia_i = -0.01;
	}
	else if (atof_julia(argv[2], vars, 1) == -1 \
		|| atof_julia(argv[3], vars, 2) == -1)
		return (print_help(0));
	else if (atof_julia(argv[2], vars, 1) == 0 \
		|| atof_julia(argv[3], vars, 2) == 0)
		return (print_help(6));
	vars->type = 'J';
	return (1);
}

int	check_args(int argc, char **argv, t_all *vars)
{
	if (argc == 1)
		return (print_help(0));
	else if (argc >= 5 || (argc >= 3 && !ft_strncmp(argv[1], "M", 1)) || \
		(argc == 3 && !ft_strncmp(argv[1], "J", 1)))
		return (print_help(4));
	else if (argc >= 2 && (ft_strncmp(argv[1], "M", 1) && \
		ft_strncmp(argv[1], "J", 1)))
		return (print_help(5));
	else if (!ft_strncmp(argv[1], "J", 1))
		return (check_julia_par(argv, vars));
	else if (!ft_strncmp(argv[1], "M", 1))
	{
		vars->type = 'M';
		return (2);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		res;
	t_all	vars;

	init_array(&vars);
	if (!check_args(argc, argv, &vars))
		return (0);
	res = create_window(&vars);
	if (res != 0)
		clear_all(&vars, res);
	return (0);
}
