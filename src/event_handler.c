#include "rtv1.h"
#include "libft.h"

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

void do_events_running(t_prog *prog)
{
	while (SDL_PollEvent(&prog->event))
	{
		if (prog->event.key.keysym.sym == SDLK_ESCAPE)
		{
			ft_putendl("Exited successfully! ESC_KEY");
			exit(1);
		}
	}
	if (prog->event.type == SDL_QUIT)
	{
		ft_putendl("Exited successfully! SDL_QUIT");
		exit(1);
	}
}
