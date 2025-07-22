/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:39:47 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/22 08:14:49 by ddamiba          ###   ########.fr       */
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
#define BLACK 0x00000000
#define WHITE 0x00FFFFFF

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
	double escape_value;
	int		i_definition;
}				t_fractal;

typedef struct s_complex
{
	double x;
	double y;
}				t_complex;

int pos_in_scale(double x, double y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void fractal_init(t_fractal *fractal);
void fractal_render(t_fractal *fractal);
int	ft_close(int keypress, t_fractal *vars);
int ft_cross_close(t_fractal *vars);
int key_hook(int keycode, t_fractal *vars);
int mouse_hook(int button, int x,int y, void *param);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex num1, t_complex num2);
t_complex square_complex(t_complex num);
#endif