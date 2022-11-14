/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:20:50 by vduchi            #+#    #+#             */
/*   Updated: 2022/11/14 10:06:59 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_float(const char *str, t_all *vars, int mod, float sign)
{
	int		i;
	float	mul;
	float	res;

	i = -1;
	mul = 10.0;
	res = 0.0;
	while (str[++i] >= '0' && str[i] <= '9')
		res = (res * 10.0) + (str[i] - '0');
	while (str[++i] >= '0' && str[i] <= '9')
	{
		res = res + ((str[i] - '0') / mul);
		mul *= 10;
	}
	if ((res * sign) > 2.0 || (res * sign) < -2.0)
	{
		error_msg(7);
		return (-1);
	}
	if (mod == 1)
		vars->fractol.julia_r = res * sign;
	else
		vars->fractol.julia_i = res * sign;
	return (1);
}

int	atof_julia(const char *str, t_all *vars, int mod)
{
	int		i;
	int		point;
	float	sign;

	i = 0;
	sign = 1.0;
	point = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\n' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			point++;
		else if (str[i] < '0' || str[i] > '9' || point > 1)
			return (0);
		i++;
	}
	return (calculate_float(str, vars, mod, sign));
}
