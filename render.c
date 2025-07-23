/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:19:11 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/23 15:48:05 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal, int x, int y)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		z->y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		z->x = 0;
		z->y = 0;
		c->x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		c->y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int i;
	int color;

	i = 0;
	mandel_or_julia(&z, &c, fractal, x, y);
	while(i < fractal->i_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (pow(z.x, 2) + pow(z.y, 2) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->i_definition);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, BLACK);
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
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
