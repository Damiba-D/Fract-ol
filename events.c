/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:36:44 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/22 12:16:55 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int keysym, t_fractal *vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
		exit (0);
	}
	return (0);
}

int ft_cross_close(t_fractal *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
	exit (0);
	return (0);
}

int key_hook(int keysym, t_fractal *vars)
{
	if (keysym == XK_Up)
		vars->shift_y += 0.5;
	else if (keysym == XK_Down)
		vars->shift_y -= 0.5;
	else if (keysym == XK_Left)
		vars->shift_x -= 0.5;
	else if (keysym == XK_Right)
		vars->shift_x += 0.5;
    else if (keysym == XK_plus)
        vars->i_definition += 10;
    else if (keysym == XK_minus)
        vars->i_definition -= 10;
    fractal_render(vars);
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