#include <SDL2/SDL.h>

#include "rtv1.h"
#include "init.h"
#include "error.h"

static void sdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		error_sdl("Could not initalize SDL");
}

void		init_program(t_prog *prog)
{
	prog->running = 1;
	prog->expose = 1;
}

void		init(t_prog *prog, char *program_name)
{
	prog->screen.window		= NULL;
	prog->screen.renderer	= NULL;
	prog->screen.texture	= NULL;
	prog->screen.width		= DEFAULT_SWIDTH;
	prog->screen.height		= DEFAULT_SHEIGHT;

	sdl_init();
	window_init(&prog->screen, program_name);
	renderer_init(&prog->screen);
	texture_init(&prog->screen);
	pixels_init(&prog->screen);
	init_program(prog);
}
