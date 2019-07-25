/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_t_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:01:23 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/23 15:43:28 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void			ft_destroy_t_screen(t_screen **screen)
{
	if (!screen || (*screen))
		return ;
	if ((*screen)->mlx_ptr && (*screen)->image_ptr)
		mlx_destroy_image((*screen)->mlx_ptr, (*screen)->image_ptr);
	if ((*screen)->mlx_ptr && (*screen)->win_ptr)
		mlx_destroy_window((*screen)->mlx_ptr, (*screen)->win_ptr);
	if ((*screen)->c_for_julia)
	{
		(*screen)->c_for_julia->a = 0.0L;
		(*screen)->c_for_julia->bi = 0.0L;
		free((*screen)->c_for_julia);
	}
	(*screen)->zoom = 0.0L;
	(*screen)->iter = 0;
	(*screen)->shift_x = 0;
	(*screen)->shift_y = 0;
	(*screen)->mlx_ptr = 0;
	(*screen)->win_ptr = 0;
	(*screen)->image_ptr = 0;
	(*screen)->mlx_data_addr = 0;
	(*screen)->c_for_julia = 0;
	free(*screen);
	*screen = 0;
}
