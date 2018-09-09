#include "rtv1.h"

void do_events(t_prog *prog)
{
	while (SDL_PollEvent(&prog->event))
	{
		if (prog->event.type == SDL_KEYDOWN)
		{
			if (prog->event.key.keysym.sym == SDLK_SPACE)
				prog->expose = 1;
			if (prog->event.key.keysym.sym == SDLK_ESCAPE)
				prog->running = 0;
		}
		if (prog->event.type == SDL_QUIT)
			prog->running = 0;
	}
}
