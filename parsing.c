/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:31:46 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/31 11:44:34 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_double(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+' || str[i] == '.') && str[i + 1] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] != '.')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	print_corr_arg(void)
{
	ft_putstr_fd("Incorrect Usage\nExpected Inputs:\n./fractol mandelbrot\n\
./fractol julia (dbl < 1 && dbl > -1) (dbl < 1 && dbl > -1)\n", 2);
}

void	arg_error(void)
{
	print_corr_arg();
	exit(EXIT_FAILURE);
}

void	check_args(char **argv)
{
	if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]) \
|| atdb(argv[2]) > 1 || atdb(argv[3]) > 1)
		arg_error();
}
