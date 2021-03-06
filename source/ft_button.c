/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:39:30 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/27 16:34:20 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				ft_button(int button, int x, int y, t_screen *screen)
{
	if (button == LEFT_BUTTON && screen->type == JULIA)
	{
		screen->mod_for_julia = !screen->mod_for_julia;
	}
	else if (button == RIGHT_BUTTON)
	{
		screen->shift_begin[0] = x;
		screen->shift_begin[1] = y;
		screen->mod_teleport = 1;
	}
	else if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		ft_zoom(button, x, y, screen);
	}
	return (SUCCESS);
}
