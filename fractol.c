/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:37:51 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/10 17:30:44 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x;
	int y;
	int x0 = 400;
	int y0 = 250;
	int height = 100;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	x = x0 - height;
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
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
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