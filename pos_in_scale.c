/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_in_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:06:47 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/18 16:47:00 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int pos_in_scale(double x, double y)
{
	int i;
	double z;
	int var;
	double I;
	double tmp;

	i = 0;
	z = 0;
	var = 50;
	I = 0;
	while(i < var)
	{	
		tmp = pow(z, 2) - pow(I, 2) + x;
		I = 2 * z * I + y;
		z = tmp;
		if (pow(z, 2) + pow(I, 2) > 4)
			break ;
		i++;
	}
	return (i);
}