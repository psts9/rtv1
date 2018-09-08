#include "rtv1.h"

void exit_program(t_prog *prog)
{
	SDL_DestroyTexture(prog->screen.texture);
	SDL_DestroyRenderer(prog->screen.renderer);
	SDL_DestroyWindow(prog->screen.window);
	SDL_Quit();
}
