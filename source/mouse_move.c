/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:35:15 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/27 16:26:32 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int					mouse_move(int x, int y, t_screen *screen)
{
	if (screen->mod_for_julia)
	{
		screen->c_for_julia->a =
			((long double)((x - 400) + (int)screen->shift_x)) /
				(800.0 / screen->zoom);
		screen->c_for_julia->bi =
			((long double)((y - 400) + (int)screen->shift_y)) /
				(800.0 / screen->zoom);
		ft_prepare(screen);
	}
	else if (screen->mod_teleport)
	{
		screen->shift_x += screen->shift_begin[0] - x;
		screen->shift_y += screen->shift_begin[1] - y;
		screen->shift_begin[0] = x;
		screen->shift_begin[1] = y;
		ft_prepare(screen);
	}
	return (SUCCESS);
}
