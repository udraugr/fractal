/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:09:09 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/25 16:28:16 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static int			ft_get_color(t_screen *screen, t_complex_numb *current)
{
	int				(*fts[3])(t_screen *screen_ft, t_complex_numb *current_ft);

	fts[0] = &julia_print;
	fts[1] = &mandelbrot_print;
	fts[2] = &burning_ship_print;
	return (fts[screen->type - 1](screen, current));
}

void				ft_print_image(t_screen *screen)
{
    int				bi;
    int				a;
    t_complex_numb	current;
    int				color;

	current.a = 0;
	current.bi = 0;
	bi = -1;
	while (++bi < 800)
	{
		a = -1;
		while (++a < 800)
		{
			current.a = ((long double)((a - 400) + screen->shift_x)) / (800.0 / screen->zoom);
			current.bi = ((long double)((bi - 400) + screen->shift_y)) / (800.0 / screen->zoom);
			color = ft_get_color(screen, &current);
			(screen->mlx_data_addr)[bi * 800 * 4 + a * 4] = (char)color;
			(screen->mlx_data_addr)[bi * 800 * 4 + a * 4 + 1] = (char)color;
			(screen->mlx_data_addr)[bi * 800 * 4 + a * 4 + 2] = (char)color;
		}
	}
	mlx_put_image_to_window(screen->mlx_ptr,
							screen->win_ptr,
							screen->image_ptr, 0, 0);
}
