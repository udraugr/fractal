NAME := fractal

INCL := include

VPATH := source

SRC :=	ft_destroy_t_screen.c\
		ft_error.c\
		ft_exit.c\
		ft_init.c\
		ft_print_fractal.c\
		ft_range.c\
		julia_print.c\
		main.c\
		mandelbrot_print.c\
		ft_print_image.c\
		burning_ship_print.c\
		ft_zoom.c

OBJ := $(patsubst %.c, %.o, $(SRC))

FLAGS := -Wall -Wextra -Werror

LIB := libftprintf

FW = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@/bin/rm -f ./libftprintf/libftprintf.a
	@make -C ./libftprintf
	@gcc $(FLAGS) -I $(INCL) -I /usr/local/include -L $(LIB) -lftprintf -L /usr/local/lib $(FW) $(OBJ) -o $(NAME)
	@printf "Make your $(NAME)!\n"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@
	@printf "Now compile $<\n"

clean:
	@/bin/rm -f $(OBJ)
	@make -C 
	@printf "Remove objects and libraries!\n"

fclean:	clean
	@/bin/rm -f $(NAME)
	@printf "Remove $(NAME)!\n"

re: fclean
