NAME = rtv1

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a
FLAGS = -Wall -Werror -Wextra -I libft -I include_sdl -L lib_sdl/lib -l SDL2-2.0.0 -I include

SRC = src/rtv1.c \
	  src/init_main.c \
	  src/init_screen.c \
	  src/error.c \
	  src/object_list.c \
	  src/loop_handler.c \
	  src/exit.c \
	  src/draw.c \
	  src/raytrace.c \
	  src/event_handler.c \
	  src/vector_math.c \
	  src/color.c \
	  src/sphere.c \
	  src/raytrace_utility_math.c \
	  src/cylinder.c \
	  src/cone.c \
	  src/plane.c \
	  src/matrix_math.c

HDR = $(wildcard include/*.h)

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	make -C $(LIBFTDIR)
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIBFT)

clean:
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

dev: FLAGS += -Wno-error
dev: all

re: fclean all

.PHONY: all clean fclean dev re
