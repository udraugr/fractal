/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:05:46 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/26 12:33:23 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int						burning_ship_print(t_screen *screen,
													t_complex_numb *current)
{
	int					iter;
	t_complex_numb		first_iter;
	long double			last_res;
	long double			tmp_a;
	long double			tmp_bi;

	iter = 0;
	last_res = ft_range(current);
	first_iter.a = current->a;
	first_iter.bi = current->bi;
	while (iter < screen->iter && iter < 255 && last_res <= 2.0L)
	{
		tmp_a = current->a * current->a - current->bi * current->bi +
																first_iter.a;
		tmp_bi = 2 * current->a * current->bi + first_iter.bi;
		tmp_a = (tmp_a < 0.0L) ? tmp_a * -1.0L : tmp_a;
		tmp_bi = (tmp_bi < 0.0L) ? tmp_bi * -1.0L : tmp_bi;
		current->a = tmp_a;
		current->bi = tmp_bi;
		last_res = ft_range(current);
		++iter;
	}
	return (((((screen->rgb[0] << 8) + screen->rgb[1]) << 8) + screen->rgb[2])
																	* iter);
}
