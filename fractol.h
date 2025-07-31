/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:39:47 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/31 11:55:27 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <math.h>

# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 1000
# define HEIGHT 1000
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define ORANGE 0x00FFA500
# define PURPLE 0x00301934

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_colors
{
	int	r_start;
	int	r_end;
	int	color;
	int	smooth;
}				t_colors;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
	void		*mlx;
	void		*win;
	t_data		img;
	double		escape_value;
	int			i_definition;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
	t_colors	colors;
	t_complex	range;
	t_complex	r_range;
}				t_fractal;

typedef struct s_atdb_vars
{
	long	inte;
	double	fract;
	double	pow;
	int		sign;
	int		i;
}				t_atdb_vars;

double		atdb(char *s);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			ft_close(int keypress, t_fractal *vars);
int			close_handler(t_fractal *vars);
int			key_hook(int keycode, t_fractal *vars);
int			mouse_hook(int button, int x, int y, t_fractal *param);
double		map(double unsc_num, t_complex range, \
double old_min, double old_max);
int			map_colors(double unsc_num, t_colors colors, \
double min, double max);
t_complex	sum_complex(t_complex num1, t_complex num2);
t_complex	square_complex(t_complex num);
void		check_args(char **argv);
void		arg_error(void);
#endif