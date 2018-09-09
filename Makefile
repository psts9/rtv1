NAME = rtv1

LIBDIR = libft/
LIB = $(LIBDIR)libft.a
FLAGS = -Wall -Werror -Wextra -I libft -I include -L libsdl/lib -l SDL2-2.0.0

SRC = src/rtv1.c \
	  src/error.c \
	  src/init_main.c \
	  src/init_screen.c \
	  src/loop_handler.c \
	  src/draw.c \
	  src/exit.c \
	  src/event_handler.c \
	  src/raytrace.c \
	  src/vector_math.c

all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIBDIR)
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIB)

clean:
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

dev: FLAGS += -Wno-error
dev: all

re: fclean all

.PHONY: all clean fclean dev re
