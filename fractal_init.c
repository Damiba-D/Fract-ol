/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:39:19 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/21 16:57:44 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void    malloc_error(void)
{
    ft_putstr_fd("Malloc Error", 2);
    exit(EXIT_FAILURE);
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
    fractal->img.bits_per_pixel = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
    
}

