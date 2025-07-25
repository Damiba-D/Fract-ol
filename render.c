/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:19:11 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/25 15:27:07 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, \
t_fractal *fractal, t_complex coords)
{
	t_complex	range;
	t_complex	r_range;

	range.x = -2;
	range.y = 2;
	r_range.x = 2;
	r_range.y = -2;
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->x = (map(coords.x, range, 0, WIDTH) * fractal->zoom) + \
fractal->shift_x;
		z->y = (map(coords.y, r_range, 0, HEIGHT) * fractal->zoom) + \
fractal->shift_y;
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		z->x = 0;
		z->y = 0;
		c->x = (map(coords.x, range, 0, WIDTH) * fractal->zoom) + \
fractal->shift_x;
		c->y = (map(coords.y, r_range, 0, HEIGHT) * fractal->zoom) + \
fractal->shift_y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	t_complex	coords;
	int			i;

	coords.x = x;
	coords.y = y;
	i = 0;
	mandel_or_julia(&z, &c, fractal, coords);
	while (i < fractal->i_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (pow(z.x, 2) + pow(z.y, 2) > fractal->escape_value)
		{
			fractal->colors.color = map_colors(i, fractal->colors, 0, fractal->i_definition);
			my_mlx_pixel_put(&fractal->img, x, y, fractal->colors.color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, fractal->colors.r_start);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
