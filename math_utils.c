/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:47:08 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/21 22:48:24 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex sum_complex(t_complex num1, t_complex num2)
{
	t_complex result;

	result.x = num1.x + num2.x;
	result.y = num1.y + num2.y;
	return (result);
}

t_complex square_complex(t_complex num)
{
	t_complex result;

	result.x = (num.x * num.x) - (num.y * num.y);
	result.y = 2 * num.x * num.y;
	return (result);
}