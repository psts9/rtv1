NAME = RTv1

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a
SDL = $(SDLDIR)/build/lib/libsdl2.a
SDLDIR = SDL2-2.0.8
FLAGS = -Wall -Werror -Wextra -Ilibft -I$(SDLDIR)/build/include -L$(SDLDIR)/build/lib -lSDL2 -Iinclude

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
	  src/light_list.c \
	  src/file_to_scene.c \
	  src/file_reading_utilities.c \
	  src/get_fileargs.c \
	  src/get_parameters.c \
	  src/shading.c \
	  src/vector_rotate.c \
	  src/vector_math_simple.c \
	  src/vector_math_simple_num.c \
	  src/vector_math_num.c

HDR = $(wildcard include/*.h)

all: $(NAME)

$(NAME): $(SRC) $(HDR) $(SDL)
	make -C $(LIBFTDIR)
	gcc $(FLAGS) $(SRC) -o $(NAME) $(LIBFT)

$(SDL):
	(cd $(SDLDIR) && \
	./configure --prefix=$$PWD/build && \
	make && \
	make install)

clean:
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(SDLDIR)/build
	make fclean -C $(LIBFTDIR)

dev: FLAGS += -Wno-error
dev: all

re: fclean all

.PHONY: all clean fclean dev re
