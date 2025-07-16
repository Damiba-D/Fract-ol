/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_mb_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:06:47 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/16 17:37:11 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int in_mb_set(double x, double y)
{
	int i;
	double z;
	int var;
	double I;

	i = 0;
	z = 0;
	var = 50;
	I = sqrt(-1);
	while(i < var)
	{
		z = pow(z, 2) + x + (y * I);
		if (z > 2)
			return (0);
		i++;
	}
	return (1);
}
