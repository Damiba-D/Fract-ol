/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:44 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/23 12:52:17 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_handler(t_fractal *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}

int	ft_close(int keysym, t_fractal *vars)
{
	if (keysym == XK_Escape)
		close_handler(vars);
	return (0);
}

int key_hook(int keysym, t_fractal *vars)
{
	if (keysym == XK_Up)
		vars->shift_y += (0.5 * vars->zoom);
	else if (keysym == XK_Down)
		vars->shift_y -= (0.5 * vars->zoom);
	else if (keysym == XK_Left)
		vars->shift_x -=(0.5 * vars->zoom);
	else if (keysym == XK_Right)
		vars->shift_x += (0.5 * vars->zoom);
    else if (keysym == XK_KP_Add)
        vars->i_definition += 10;
    else if (keysym == XK_KP_Subtract)
        vars->i_definition -= 10;
    fractal_render(vars);
	return (0);
}

int mouse_hook(int button, int x,int y, t_fractal *param)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		param->zoom *=1.05;
	}
	else if (button == Button4)
	{
		param->zoom *=0.95;
	}
	fractal_render(param);
	return (0);
}