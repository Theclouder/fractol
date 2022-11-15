/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:08:54 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/15 20:28:46 by vduchi           ###   ########.fr       */
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
	ft_printf("\t3. B (for Burning Ship)\n");
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
	vars->string = "Julia";
	return (1);
}

int	check_args(int argc, char **argv, t_all *vars)
{
	if (argc == 1)
		return (print_help(0));
	else if (argc >= 5 || (argc >= 3 && !ft_strncmp(argv[1], "M", 1)) || \
		(argc == 3 && !ft_strncmp(argv[1], "J", 1)) || (argc >= 3 && \
		!ft_strncmp(argv[1], "B", 1)))
		return (print_help(4));
	else if (argc >= 2 && (ft_strncmp(argv[1], "M", 1) && \
		ft_strncmp(argv[1], "J", 1)) && ft_strncmp(argv[1], "B", 1))
		return (print_help(5));
	else if (!ft_strncmp(argv[1], "J", 1))
		return (check_julia_par(argv, vars));
	else if (!ft_strncmp(argv[1], "M", 1))
	{
		vars->type = 'M';
		vars->string = "Mandelbrot";
		return (1);
	}
	else if (!ft_strncmp(argv[1], "B", 1))
	{
		vars->type = 'B';
		vars->string = "Burning Ship";
		return (1);
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
