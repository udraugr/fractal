/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_realise.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:19:40 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/27 16:35:58 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			ft_button_realise(int button, int x, int y, t_screen *screen)
{
	int		a;

	if (button == RIGHT_BUTTON)
	{
		a = x - y;
		screen->mod_teleport = 0;
	}
	return (SUCCESS);
}
