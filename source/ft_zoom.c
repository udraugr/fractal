/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:53:34 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/27 13:59:00 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				ft_zoom(int buttom, int x, int y, t_screen *screen)
{
	if (buttom == SCROLL_UP)
	{
		screen->shift_x = (float)((x - 400) * 0.8L - (x - 400)) +
												screen->shift_x * 0.8;
		screen->shift_y = (float)(y - 400) * 0.8L - (y - 400) +
												screen->shift_y * 0.8;
		screen->zoom *= 1.25L;
	}
	else if (buttom == SCROLL_DOWN)
	{
		screen->shift_x = (float)((x - 400) * 1.25L - (x - 400)) +
												screen->shift_x * 1.25;
		screen->shift_y = (float)((y - 400) * 1.25L - (y - 400)) +
												screen->shift_y * 1.25;
		screen->zoom *= 0.8L;
	}
	ft_prepare(screen);
	return (0);
}
