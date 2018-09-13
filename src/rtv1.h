#ifndef RTV1_H
# define RTV1_H

# include <SDL2/SDL.h>

# define RES_X 1024
# define RES_Y 720

# define SAMPLING_AMOUNT 40
# define MIN_REFLECT_FLOAT 0.00001
# define GAMMA 0.5
# define MAX_DEPTH 50

# define THREADS 4

typedef struct		s_screen
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	uint32_t		pixels[RES_X * RES_Y];
}					t_screen;

typedef struct		s_prog
{
	char			*name;
	int				running;
	int				expose;
	t_screen		screen;
	SDL_Event		event;
}					t_prog;

#endif
