/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtown_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:19:19 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/27 14:09:00 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void			ft_calc(t_complex_numb *current)
{
	long double		a;
	long double		bi;
	long double		delitel;
	long double		delimoe;
	long double		tmp;

	a = current->a;
	bi = current->bi;
	tmp = 3.0L * (a * a - bi * bi);
	delimoe = tmp;
	tmp *= tmp;
	tmp += 36.0L * a * a * bi * bi;
	delitel = tmp;
	current->a = (2.0L / 3.0L) * a + delimoe / delitel;
	current->bi = (2.0L / 3.0L) * bi + (-6.0L * a * bi) / delitel;
}

static int			ft_roots(t_complex_numb *current, t_screen *screen)
{
	int				sektor;
	int				ans;

	sektor = current->bi / current->a;
	if (sektor == 0)
	{
		ans = ((screen->rgb[0] << 8) + screen->rgb[1]) << 8;
	}
	else if (sektor == 1)
	{
		ans = (screen->rgb[1] << 8) + screen->rgb[2];
	}
	else
	{
		ans = (screen->rgb[0] << 16) + screen->rgb[2];
	}
	return (ans);
}

int					newton_print(t_screen *screen, t_complex_numb *current)
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
