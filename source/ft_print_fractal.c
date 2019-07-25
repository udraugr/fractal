/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:46:55 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/25 20:39:22 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static int		ft_color_managment(t_screen *screen, int key)
{
	if (key == RED_PLUS)
		screen->rgb[0] = (screen->rgb[0] + 1 < 256) ?
												screen->rgb[0] + 1 : 255
	else if (key == GREEN_PLUS)
		screen->rgb[1] = (screen->rgb[1] + 1 < 256) ?
												screen->rgb[1] + 1 : 255;
	else if (key == BLUE_PLUS)
		screen->rgb[2] = (screen->rgb[2] + 1 < 256) ?
												screen->rgb[2] + 1 : 255;
	else if (key == RED_MINUS)
		screen->rgb[0] = (screen->rgb[0] - 1 > 0) ?
												screen->rgb[0] - 1 : 0;
	else if (key == GREEN_MINUS)
		screen->rgb[1] = (screen->rgb[1] - 1 > 0) ?
												screen->rgb[1] - 1 : 0;
	else if (key == BLUE_MINUS)
		screen->rgb[2] = (screen->rgb[2] - 1 > 0) ?
												screen->rgb[2] - 1 : 0;
	else
		return (FAIL);
	return (SUCCESS);
}

static int		ft_key(int key, t_screen *screen)
{
	if (key == ESC)
		ft_exit(key, screen);
	else if (key == ARROW_LEFT)
		screen->shift_x += 10;
	else if (key == ARROW_RIGHT)
		screen->shift_x -= 10;
	else if (key == ARROW_UP)
		screen->shift_y += 10;
	else if (key == ARROW_DOWN)
		screen->shift_y -= 10;
	else if (key == PLUS)
		screen->iter += 10;
	else if (key == MINUS)
		screen->iter = (screen->iter > 9) ? screen->iter - 10 : 0;
	else if (ft_color_managment(screen, key) == FAIL)
		return (0);
	ft_print_image(screen);
	return (0);
}

void			ft_print_fractal(int type)
{
	t_screen	*screen;

	if (!(screen = ft_init(type)))
		ft_error(1);
	ft_print_image(screen);
	mlx_hook(screen->win_ptr, 2, 1L << 0, ft_key, (void *)screen);
	mlx_hook(screen->win_ptr, 4, 1L << 2, ft_zoom, (void *)screen);
	mlx_hook(screen->win_ptr, 17, 1L << 17, ft_exit, (void *)screen);
	mlx_loop(screen->mlx_ptr);
}
