/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:46:55 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/22 18:52:29 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void		ft_distribution(t_screen *screen)
{
	if (screen->type == JULIA)
		julia_print(screen);
//	else if (screen->type == MANDELBROT)
//		mandelbrot_print(screen);
}

static int		ft_key(int key, t_screen *screen)
{
	if (key == ESC)
		ft_exit(screen);
	//else
	//	ft_printf("\n%d\n", key, screen->mlx_ptr);
	//ft_distribution(screen);
	return (0);
}

void			ft_print_fractal(int type)
{
	t_screen	*screen;

	if (!(screen = ft_init(type)))
		ft_error(1);
	ft_distribution(screen);
	mlx_key_hook(screen->win_ptr, ft_key, (void *)screen);
	mlx_loop(screen->mlx_ptr);
}
