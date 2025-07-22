/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:19:11 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/22 08:12:34 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int i;
	int color;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);
	while(i < fractal->i_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (pow(z.x, 2) + pow(z.y, 2) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->i_definition);
			my_mlx_pixel_put();
			return ;
		}
	}
}

void fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	x = -1;
	while(++x < WIDTH)
	{
		y = -1;
		while(++y < HEIGHT)
		{
			handle_pixel(x, y, fractal);
		}
	}
}