/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:39:30 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/26 12:33:57 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				ft_button(int button, int x, int y, t_screen *screen)
{
	if (button == LEFT_BUTTON && screen->type == JULIA)
	{
		screen->mod_for_julia = !screen->mod_for_julia;
	}
	else if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		ft_zoom(button, x, y, screen);
	}
	return (SUCCESS);
}
