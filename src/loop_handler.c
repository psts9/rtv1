#include "rtv1.h"
#include "exit.h"
#include "events.h"
#include "raytrace.h"

#include <stdio.h>

void	update_screen(t_screen *screen)
{
	SDL_UpdateTexture(screen->texture, NULL, screen->pixels, RES_X * sizeof(uint32_t));
	SDL_RenderClear(screen->renderer);
	SDL_RenderCopy(screen->renderer, screen->texture, 0, 0);
	SDL_RenderPresent(screen->renderer);
}

void	run(t_prog *prog)
{
	while (prog->running)
	{
		if (prog->expose == 1)
		{
			raytrace(prog);
			update_screen(&prog->screen);
			prog->expose = 0;
		}
		do_events(prog);
		SDL_Delay(30);
	}
	exit_program(prog);
}
