/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:37:51 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/16 17:58:50 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* void	draw_hexagon(t_data *img, int x0, int y0, int side, int color)
{
	int dx = (int)((sqrt(3) / 2) * side);
	int top_height = side / 2;
	int middle_height = side;
	int bottom_height = top_height;
	int y = y0 - side;

	// Top trapezoid
	int dy = 0;
	while (dy < top_height)
	{
		int line_dx = dx * dy / top_height;
		int x_start = x0 - line_dx;
		int x_end = x0 + line_dx;

		int x = x_start;
		while (x <= x_end)
		{
			my_mlx_pixel_put(img, x, y + dy, color);
			x++;
		}
		dy++;
	}

	// Middle rectangle
	int mid_y = y + dy;
	int mid_dy = 0;
	while (mid_dy < middle_height)
	{
		int x_start = x0 - dx;
		int x_end = x0 + dx;

		int x = x_start;
		while (x <= x_end)
		{
			my_mlx_pixel_put(img, x, mid_y + mid_dy, color);
			x++;
		}
		mid_dy++;
	}
	dy += middle_height;

	// Bottom trapezoid
	int bot_dy = 0;
	while (bot_dy < bottom_height)
	{
		int line_dx = dx * (bottom_height - bot_dy) / bottom_height;
		int x_start = x0 - line_dx;
		int x_end = x0 + line_dx;

		int x = x_start;
		while (x <= x_end)
		{
			my_mlx_pixel_put(img, x, y + dy + bot_dy, color);
			x++;
		}
		bot_dy++;
	}
} */

//fazer funcao para verificar se uma coord faz parte do mandelbrot set
//fazer uma funcao que traduza um pixel para coordenada

int	main(int argc, char **argv)
{
/* 	void	*mlx;
	void	*mlx_win;
	t_data	img;

	int x0 = 500;
	int y0 = 500;
	int side = 80; */

	/* mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	if (!x0 || !y0 || !side)
		return 0;
	draw_hexagon(&img, x0, y0, side, 0x000000FF);
	// Render image to window
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx); */
	t_fractal fractal;
	
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)\
		|| argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
			fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("ERROR\n", 2);
		return (-1);
	}
	if (in_mb_set(0.5, 0.5))
		ft_printf("ITS IN\n");
	else
		ft_printf("ITS OUT\n");
	
}
//Draw 81x81 square

/* x = 360;
	while (x <= 440)
	{
		y = 210;
		while (y <= 290)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	} */

//Draw circle
/* x = x0 - radius;
	while (x <= x0 + radius)
	{
		y = y0 - radius;
		while (y <= y0 + radius)
		{
			if ((x - x0)*(x - x0) + (y - y0)*(y - y0) <= radius * radius)
			{
				my_mlx_pixel_put(&img, x, y, 0x0000FF00); // Green circle
			}
			y++;
		}
		x++;
	} */

//Draw triangle
/* x = x0 - height;
	int y_offset = 0;
	while (y_offset <= height)
	{
		y = y0 + height / 2;
		while (y >= y0 + height / 2 - y_offset)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000FF); // Blue pixel
			y--;
		}
		y_offset++;
		x++;
	}
	x = x0 + height;
	y_offset = 0;
	while (y_offset <= height)
	{
		y = y0 + height / 2;
		while (y >= y0 + height / 2 - y_offset)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000FF);
			y--;
		}
		y_offset++;
		x--;
	} */


