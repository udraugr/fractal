/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:05:11 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/22 18:54:01 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static int			ft_get_color(t_screen *screen, t_complex_numb current)
{
	int				iter;
	long double		last_res;
	long double		tmp_a;
	long double		tmp_bi;

	iter = 0;
	last_res = ft_range(current);
	while (iter < screen->iter && last_res <= 2.0L)
	{
		tmp_a = current.a * current.a - current.bi * current.bi + screen->c_for_julia->a;
		tmp_bi = 2 * current.a * current.bi + screen->c_for_julia->bi;
		current.a = tmp_a;
		current.bi = tmp_bi;
		last_res = ft_range(current);
		++iter;
	}
	return (iter);
}

void				julia_print(t_screen *screen)
{
	int				bi;
	int				a;
	t_complex_numb	current;
	int				color;

	bi = 0;
	while (bi < 800)
	{
		a = 0;
		while (a < 800)
		{
			current.a = ((long double)((a - 400) + screen->shift_x)) / (800.L / screen->zoom);
			current.bi = ((long double)((bi - 400) + screen->shift_y)) / (800.L / screen->zoom);
			color = ft_get_color(screen, current);
			((char *)screen->image_ptr)[bi * 800 + a] = color;
			((char *)screen->image_ptr)[bi * 800 + a + 1] = color;
			((char *)screen->image_ptr)[bi * 800 + a + 2] = color;
			++a;
		}
		++bi;
	}
	mlx_put_image_to_window (screen->mlx_ptr, screen->win_ptr, screen->image_ptr, 0, 0);
}
