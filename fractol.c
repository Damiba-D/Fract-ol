/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:37:51 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/21 17:02:44 by ddamiba          ###   ########.fr       */
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

int add_shade(double shade, int color)
{
	if (shade == 0)
		return (color);
    int r = ((color >> 16) & 0xFF) * shade;
    int g = ((color >> 8) & 0xFF) * shade;
    int b = (color & 0xFF) * shade;

    return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}


int set_color_shade(int x, int y)
{
	int color;
	double shade;

	color = 0x00FFFFFF;
	shade = 100.0 - ((double)pos_in_scale((double)x, (double)y) / 50.0 * 100);
	color = add_shade(shade, color);
	return (color);
}

int	ft_close(int keypress, t_fractal *vars)
{
	if (keypress == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int ft_cross_close(t_fractal *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int key_hook(int keycode, t_fractal *vars)
{
	(void)vars;
	if (keycode == XK_Up)
		ft_printf("UP\n");
	else if (keycode == XK_Down)
		ft_printf("DOWN\n");
	else if (keycode == XK_Left)
		ft_printf("LEFT\n");
	else if (keycode == XK_Right)
		ft_printf("RIGHT\n");
	return (0);
}

int mouse_hook(int button, int x,int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	if (button == Button4)
		ft_printf("SCROLLUP\n");
	else if (button == Button5)
		ft_printf("SCROLLDOWN\n");
	return (0);
}

/* int render_next_frame(void *param)
{
	
} */

int	main(int argc, char **argv)
{
/* 	t_fractal vars;
	//t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, ft_cross_close, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, ft_close, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx); */
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
	if (pos_in_scale(0.5, 0.5) == 50)
		ft_printf("ITS IN\n");
	else
		ft_printf("ITS OUT\n");
}


