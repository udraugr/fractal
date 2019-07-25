/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:53:34 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/25 16:20:13 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int				ft_zoom(int buttom, int x, int y, t_screen *screen)
{
	int			tmp;

	if (buttom == SCROLL_UP)
	{
		tmp = 0;//(int)(screen->shift_x * 0.8);
		screen->shift_x += (x - 400) * 0.8L - (x - 400) - tmp;
		tmp = 0;//(int)(screen->shift_y * 0.8L);
		screen->shift_y += (y - 400) * 0.8L - (y - 400) - tmp;
		screen->zoom *= 1.25L;
	}
	else if (buttom == SCROLL_DOWN)
	{
		tmp = 0;//(int)(screen->shift_x * 1.25L);
		screen->shift_x += (x - 400) * 1.25L - (x - 400) - tmp;
		tmp = 0;//(int)(screen->shift_y * 1.25L);
		screen->shift_y += (y - 400) * 1.25L - (y - 400) - tmp;
		screen->zoom *= 0.8L;
	}
	ft_print_image(screen);
	return (0);
}
