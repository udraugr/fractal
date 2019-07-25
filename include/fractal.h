/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:57:03 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/25 16:17:08 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../libftprintf/ft_printf/printf.h"
# include <math.h>
# include <mlx.h>

# define JULIA 1
# define MANDELBROT 2
# define BURNING_SHIP 3

# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DOWN 125
# define PLUS 69
# define MINUS 78
# define SCROLL_UP 4
# define SCROLL_DOWN 5 

# define SUCCESS 0
# define FAIL 1

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
	char			*mlx_data_addr;
	int				type;
	int				iter;
	long double		zoom;
	int				shift_x;
	int				shift_y;
	t_complex_numb	*c_for_julia;

}					t_screen;

void				ft_print_fractal(int type);

t_screen			*ft_init(int type);
void				ft_destroy_t_screen(t_screen **screen);

long double			ft_range(t_complex_numb *current);

void				ft_print_image(t_screen *screen);

int					ft_zoom(int buttom, int x, int y, t_screen *screen);

int					julia_print(t_screen *screen,
								t_complex_numb *current);
int					mandelbrot_print(t_screen *screen,
								t_complex_numb *current);
int					burning_ship_print(t_screen *screen,
								t_complex_numb *current);

int					ft_exit(int key, t_screen *screen);

void				ft_error(int error);

#endif
