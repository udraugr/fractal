/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:05:11 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/25 20:32:21 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int					julia_c_release(int x, int y, t_screen *screen)
{
	//if (button == LEFT_BUTTON)
	//{
		screen->c_for_julia->a =
			((long double)((x - 400) + (int)screen->shift_x)) /
						(800.0 / screen->zoom);
		screen->c_for_julia->bi =
			((long double)((y - 400) + (int)screen->shift_y)) /
						(800.0 / screen->zoom);	
	//}
	ft_print_image(screen);
	return (SUCCESS);
}

int					julia_print(t_screen *screen, t_complex_numb *current)
{
	int				iter;
	long double		last_res;
	long double		tmp_a;
	long double		tmp_bi;

	//mlx_hook(screen->win_ptr, 5, 1L << 3, julia_c_release, screen);
	mlx_hook(screen->win_ptr, 6, 1L << 3, julia_c_release, screen);
	iter = 0;
	last_res = ft_range(current);
	while (iter < screen->iter && iter < 255 && last_res <= 2.0L)
	{
		tmp_a = current->a * current->a - current->bi * current->bi +
						((t_complex_numb *)screen->c_for_julia)->a;
		tmp_bi = 2 * current->a * current->bi +
						((t_complex_numb *)screen->c_for_julia)->bi;
		current->a = tmp_a;
		current->bi = tmp_bi;
		last_res = ft_range(current);
		++iter;
	}
	return (iter);
}
