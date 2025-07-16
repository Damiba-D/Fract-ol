/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:39:47 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/16 17:52:32 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_data	img;
	
	
}				t_fractal;

int in_mb_set(double x, double y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif