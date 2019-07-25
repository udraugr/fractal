/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:56:26 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/25 14:05:28 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void			ft_print_set_fractals(void)
{
	ft_putstr("\t\t1)Julia\n\t\t2)Mandelbrot\n\t\t3)Burning_Ship\n");
}

static void			ft_help(void)
{
	ft_putstr("./fractal [name_of_fractal]\n");
	ft_print_set_fractals();
}

static int			ft_name_detector(char *name_of_fractal)
{
	ft_strtolower(name_of_fractal);
	if (ft_strequ(name_of_fractal, "julia"))
		return (JULIA);
	else if (ft_strequ(name_of_fractal, "mandelbrot"))
		return (MANDELBROT);
	else if (ft_strequ(name_of_fractal, "burning_ship"))
		return (BURNING_SHIP);
	else
		return (0);
}

int					main(int argc, char **argv)
{
	int				fractal;

	if (argc == 1)
		ft_help();
	else
	{
		fractal = ft_name_detector(argv[1]);
		if (fractal == 0)
		{
			ft_putstr("What you meen?\n");
			ft_print_set_fractals();
		}
		else
			ft_print_fractal(fractal);
	}
	return (0);
}
