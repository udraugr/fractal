/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:24:29 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/22 19:32:12 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void		ft_fill_new_t_screen(t_screen *new)
{
	new->zoom = 6.0L;
	new->shift_x = 0;
	new->shift_y = 0;
	new->type = type;
	new->iter = 50;
	new->c_for_julia->a = 0;
	new->c_for_julia->bi = 0;
}

t_screen		*ft_init(int type)
{
	t_screen	*new;

	if (!(new = (t_screen *)malloc(sizeof(t_screen))))
		return (0);
	if (!(new->c_for_julia = (t_complex_numb *)malloc(sizeof(t_complex_numb))))
	{
		free(new);
		new = 0;
		return (0);
	}
	if (!(new->mlx_ptr = mlx_init()) ||
		!(new->win_ptr = mlx_new_window(new->mlx_ptr, 800, 800, "Fractal")) ||
		!(new->image_ptr = mlx_new_image(new->mlx_ptr, 800, 800)))
	{
		mlx_destroy_window(new->mlx_ptr, new->win_ptr);
		mlx_destroy_image(new->mlx_ptr, new->image_ptr); // ft_bzero
		free(new);
		new = 0;
		return (0);
	}
	ft_fill_new_t_screen(new);
	return (new);
}
