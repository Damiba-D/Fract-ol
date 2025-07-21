/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:39:47 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/21 17:05:42 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/get_next_line/get_next_line.h"
#include "minilibx/mlx.h"
#include "minilibx/mlx_int.h"
#include <math.h>

#include <X11/X.h>
#include <X11/keysym.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractal
{
	char *name;
	void	*mlx;
	void	*win;
	t_data	img;
}				t_fractal;

int pos_in_scale(double x, double y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void fractal_init(t_fractal *fractal);
void fractal_render(t_fractal *fractal);
#endif