/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:47:08 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/23 21:09:46 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unsc_num, t_complex range, double old_min, double old_max)
{
	return ((range.y - range.x) * (unsc_num - old_min) \
/ (old_max - old_min) + range.x);
}

double	map_colors(double unsc_num, t_colors colors, double min, double max)
{
	return ((colors.r_end - colors.r_start) * (unsc_num - min) \
/ (max - min) + colors.r_start);
}

t_complex	sum_complex(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.x = num1.x + num2.x;
	result.y = num1.y + num2.y;
	return (result);
}

t_complex	square_complex(t_complex num)
{
	t_complex	result;

	result.x = (num.x * num.x) - (num.y * num.y);
	result.y = 2 * num.x * num.y;
	return (result);
}

double	atdb(char *s)
{
	t_atdb_vars	vars;

	vars.inte = 0;
	vars.fract = 0;
	vars.sign = 1;
	vars.pow = 1;
	vars.i = 0;
	while (ft_isspace(s[vars.i]))
		vars.i++;
	if (s[vars.i] == '+' || s[vars.i] == '-')
	{
		if (s[vars.i] == '-')
			vars.sign *= -1;
		vars.i++;
	}
	while ((s[vars.i] != '.' && ft_isdigit(s[vars.i])) && s[vars.i])
		vars.inte = (vars.inte * 10) + (s[vars.i++] - '0');
	if (s[vars.i] == '.')
		vars.i++;
	while (ft_isdigit(s[vars.i]) && s[vars.i])
	{
		vars.pow /= 10;
		vars.fract += (s[vars.i++] - '0') * vars.pow;
	}
	return ((vars.inte + vars.fract) * vars.sign);
}
