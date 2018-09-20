#include <SDL2/SDL.h>

#include "rtv1.h"
#include "libft.h"
#include "error.h"

void	window_init(t_screen *screen, char *program_name)
{
	screen->window = SDL_CreateWindow
	(
		program_name,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		RES_X,
		RES_Y,
		SDL_WINDOW_SHOWN
	);
	if (!screen->window)
		error_sdl("Could not initalize window");
}

void	renderer_init(t_screen *screen)
{
	screen->renderer = SDL_CreateRenderer
	(
		screen->window,
		-1,
		SDL_RENDERER_ACCELERATED
	);
	if (!screen->renderer)
		error_sdl("Could not initialize renderer");
	SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, 0);
}

void	texture_init(t_screen *screen)
{
	screen->texture = SDL_CreateTexture
	(
		screen->renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC,
		RES_X,
		RES_Y
	);
	if (!screen->texture)
		error_sdl("Could not initialize texture");
}

void	pixels_init(t_screen *screen)
{
	ft_bzero(screen->pixels, RES_X * RES_Y * sizeof(uint32_t));
}
