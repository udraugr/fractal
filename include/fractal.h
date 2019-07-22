/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:57:03 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/22 19:32:26 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../libftprintf/ft_printf/printf.h"
# include <math.h>
# include <mlx.h>

# define JULIA 1
# define MANDELBROT 2

# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DOWN 125

typedef struct		s_complex_numb
{
	long double		a;
	long double		bi;
}					t_complex_numb;

typedef struct		s_screen
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	int				type;
	int				iter;
	long double		zoom;
	int				shift_x;
	int				shift_y;
	t_complex_numb	*c_for_julia;

}					t_screen;

void				ft_print_fractal(int type);

t_screen			*ft_init(int type);

long double			ft_range(t_complex_numb current);

void				julia_print(t_screen *screen);

void				ft_exit(t_screen *screen);

void				ft_error(int error);

#endif
