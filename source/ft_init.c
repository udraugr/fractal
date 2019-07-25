/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:24:29 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/25 18:48:44 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

static void		ft_fill_new_t_screen(t_screen *new, int type)
{
	new->zoom = 6.0L;
	new->shift_x = 0.0f;
	new->shift_y = 0.0f;
	new->type = type;
	new->iter = 100;
	new->c_for_julia->a = 0.0L;
	new->c_for_julia->bi = 0.0L;
	new->rgb[0] = 2;
	new->rgb[1] = 1;
	new->rgb[2] = 5;

}

static int		ft_system_calls(t_screen *new)
{
	int			size_line;
	int			bits_per_pixel;
	int			endian;

	size_line = 800 * 4;
	bits_per_pixel = 4 * 8;
	endian = 0;
	if (!(new->c_for_julia =
				(t_complex_numb *)malloc(sizeof(t_complex_numb))) ||
		!(new->mlx_ptr = mlx_init()) ||
		!(new->win_ptr = mlx_new_window(new->mlx_ptr,
												800, 800, "Fractal")) ||
		!(new->image_ptr = mlx_new_image(new->mlx_ptr, 800, 800)) ||
		!(new->mlx_data_addr = mlx_get_data_addr(new->image_ptr,
												&bits_per_pixel,
												&size_line,
												&endian)))
		return (FAIL);
	return (SUCCESS);
}

t_screen		*ft_init(int type)
{
	t_screen	*new;

	if (!(new = (t_screen *)malloc(sizeof(t_screen))))
		return (0);
	new->mlx_ptr = 0;
	new->win_ptr = 0;
	new->image_ptr = 0;
	new->mlx_data_addr = 0;
	new->c_for_julia = 0;
	if (ft_system_calls(new) == FAIL)
	{
		ft_destroy_t_screen(&new);
		return (0);
	}
	ft_fill_new_t_screen(new, type);
	return (new);
}
