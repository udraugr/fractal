/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_pro_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:36:15 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/27 15:21:12 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void			ft_calc(t_complex_numb *current)
{
	long double		a;
	long double		bi;
	long double		a_t;
	long double		bi_t;

	a = current->a;
	bi = current->bi;
	a_t = a * a * a * a + bi * bi * bi * bi - 6.0L * a * a * bi * bi;
	bi_t = 4.0L * a * bi * (a * a - bi * bi);
	current->a = (4.0L / 5.0L) * a +
					a_t / (a_t * a_t + bi_t * bi_t);
	current->bi = (4.0L / 5.0L) * bi +
					(-1.0L * bi_t) / (a_t * a_t + bi_t * bi_t);
}

static int			ft_roots(t_complex_numb *current, t_screen *screen)
{
	int				sektor;
	int				ans;
	long double		dlina;
	long double		angle;

	ans = 0;
	sektor = (current->bi < 0.0L) ? -1 : 1;
	dlina = ft_range(current);
	angle = (current->a == dlina || current->a == -1.0L * dlina) ?
		M_PI : acos(current->a / dlina);
	sektor = ((sektor == 1) ? angle : 2.0L * M_PI - angle) / (M_PI / 2.5L);
	if ((int)sektor == 0)
		ans = screen->rgb[0] << 16;
	else if ((int)sektor == 1)
		ans = ((screen->rgb[0] << 8) + screen->rgb[1]) << 8;
	else if ((int)sektor == 2)
		ans = screen->rgb[1] << 8;
	else if ((int)sektor == 3)
		ans = (screen->rgb[1] << 8) + screen->rgb[2];
	else
		ans = (((screen->rgb[0] << 8) + screen->rgb[1]) << 8)
			+ screen->rgb[2];
	return (ans);
}

int					newton_pro_print(t_screen *screen, t_complex_numb *current)
{
	int				iter;
	long double		last_res;
	int				ans;

	iter = 0;
	last_res = ft_range(current);
	while (iter < screen->iter && iter < 255 && last_res <= 10)
	{
		ft_calc(current);
		last_res = ft_range(current);
		++iter;
	}
	ans = ft_roots(current, screen);
	return (ans * iter);
}
