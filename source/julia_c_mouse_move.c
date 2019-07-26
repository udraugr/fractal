/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_c_mouse_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:49:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/26 12:35:15 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int					julia_c_mouse_move(int x, int y, t_screen *screen)
{
	if (screen->mod_for_julia)
	{
		screen->c_for_julia->a =
			((long double)((x - 400) + (int)screen->shift_x)) /
				(800.0 / screen->zoom);
		screen->c_for_julia->bi =
			((long double)((y - 400) + (int)screen->shift_y)) /
				(800.0 / screen->zoom);
		ft_print_image(screen);
	}
	return (SUCCESS);
}
