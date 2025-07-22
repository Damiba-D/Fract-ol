/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:37:51 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/22 11:37:09 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
 
//fazer funcao para verificar se uma coord faz parte do mandelbrot set
//fazer uma funcao que traduza um pixel para coordenada


int	main(int argc, char **argv)
{
	t_fractal fractal;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))\
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
			fractal.name = argv[1];
			fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd("ERROR\n", 2);
		return (-1);
	} 
}


