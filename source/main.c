/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:56:26 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/26 15:38:50 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void			ft_print_set_fractols(void)
{
	ft_putstr("\t\t1)Julia\n\t\t2)Mandelbrot\n\t\t3)Burning_Ship\n");
	ft_putstr("\t\t4)Newton\n\t\t5)Newton_pro\n");
}

static void			ft_help(void)
{
	ft_putstr("./fractol [name_of_fractal]\n");
	ft_print_set_fractols();
}

static int			ft_name_detector(char *name_of_fractol)
{
	ft_strtolower(name_of_fractol);
	if (ft_strequ(name_of_fractol, "julia"))
		return (JULIA);
	else if (ft_strequ(name_of_fractol, "mandelbrot"))
		return (MANDELBROT);
	else if (ft_strequ(name_of_fractol, "burning_ship"))
		return (BURNING_SHIP);
	else if (ft_strequ(name_of_fractol, "newton"))
		return (NEWTON);
	else if (ft_strequ(name_of_fractol, "newton_pro"))
		return (NEWTON_PRO);
	else
		return (0);
}

int					main(int argc, char **argv)
{
	int				fractol;

	if (argc == 1)
		ft_help();
	else
	{
		fractol = ft_name_detector(argv[1]);
		if (fractol == 0)
		{
			ft_putstr("What you meen?\n");
			ft_print_set_fractols();
		}
		else
			ft_print_fractol(fractol);
	}
	return (0);
}
