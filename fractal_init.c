/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:39:19 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/22 12:11:49 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void malloc_error(void)
{
    ft_putstr_fd("Malloc Error", 2);
    exit(EXIT_FAILURE);
}

static void data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->i_definition = 50;
    fractal->shift_x = 0;
    fractal->shift_y = 0;
}

static void events_init(t_fractal *fractal)
{
    mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_hook(fractal->win, DestroyNotify, NoEventMask, ft_cross_close, fractal);
	mlx_hook(fractal->win, KeyPress, KeyPressMask, ft_close, fractal);
}

void fractal_init(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    if (fractal->mlx == NULL)
        malloc_error();
    fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
    if (fractal->win == NULL)
    {
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        malloc_error();
    }
    fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (fractal->img.img == NULL)
    {
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        malloc_error();
    }
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
    events_init(fractal);
    data_init(fractal);
}

