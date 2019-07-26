/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:09:09 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/26 12:36:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int			ft_get_color(t_screen *screen, t_complex_numb *current)
{
	int				(*fts[3])(t_screen *screen_ft, t_complex_numb *current_ft);

	fts[0] = &julia_print;
	fts[1] = &mandelbrot_print;
	fts[2] = &burning_ship_print;
	return (fts[screen->type - 1](screen, current));
}

static void			ft_color_fill(t_screen *screen, int a, int bi, int color)
{
	int				r;
	int				g;
	int				b;

	r = color >> 16;
	r = (r > 255) ? 255 : r;
	g = (color >> 8) % 256;
	g = (g > 255) ? 255 : g;
	b = color % 256;
	b = (b > 255) ? 255 : b;
	(screen->mlx_data_addr)[bi * 800 * 4 + a * 4] = b;
	(screen->mlx_data_addr)[bi * 800 * 4 + a * 4 + 1] = g;
	(screen->mlx_data_addr)[bi * 800 * 4 + a * 4 + 2] = r;
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
			current.a = ((long double)((a - 400) + (int)screen->shift_x)) /
									(800.0 / screen->zoom);
			current.bi = ((long double)((bi - 400) + (int)screen->shift_y)) /
									(800.0 / screen->zoom);
			color = ft_get_color(screen, &current);
			ft_color_fill(screen, a, bi, color);
		}
	}
	mlx_put_image_to_window(screen->mlx_ptr,
							screen->win_ptr,
							screen->image_ptr, 0, 0);
}
