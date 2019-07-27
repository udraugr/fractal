/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:05:11 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/26 14:31:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int					julia_print(t_screen *screen, t_complex_numb *current)
{
	int				iter;
	long double		last_res;
	long double		tmp_a;
	long double		tmp_bi;
	int				ans;

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
	ans = ((((screen->rgb[0] << 8) + screen->rgb[1]) << 8) + screen->rgb[2])
																	* iter;
	return (ans);
}
