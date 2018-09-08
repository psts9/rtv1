#ifndef RTV1_H
# define RTV1_H

# include <SDL2/SDL.h>

# define RES_X 1680
# define RES_Y 1050

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
	t_screen		screen;
	SDL_Event		event;
}					t_prog;

#endif
