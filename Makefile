NAME := fractol

INCL := include

VPATH := source

SRC :=	burning_ship_print.c\
		ft_button.c\
		ft_destroy_t_screen.c\
		ft_error.c\
		ft_exit.c\
		ft_init.c\
		ft_print_fractal.c\
		ft_print_image.c\
		ft_range.c\
		ft_zoom.c\
		mouse_move.c\
		julia_print.c\
		main.c\
		mandelbrot_print.c\
		newton_print.c\
		newton_pro_print.c\
		ft_button_realise.c

OBJ := $(patsubst %.c, %.o, $(SRC))

FLAGS := -Wall -Wextra -Werror

LIB := libftprintf

FW = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@/bin/rm -f ./libftprintf/libftprintf.a
	@make -C ./libftprintf
	@make -C minilibx_macos
	@clang $(FLAGS) -I $(INCL) -L $(LIB) -lftprintf -L minilibx_macos -lmlx $(FW) $(OBJ) -o $(NAME)
	@printf "Make your $(NAME)!\n"

%.o: %.c
	@clang $(FLAGS) -c $< -o $@
	@printf "Now compile $<\n"

clean:
	@/bin/rm -f $(OBJ)
	@make -C ./libftprintf fclean
	@make -C ./minilibx_macos clean
	@printf "Remove objects and libraries!\n"

fclean:	clean
	@/bin/rm -f $(NAME)
	@printf "Remove $(NAME)!\n"

re: fclean all
