#include "rtv1.h"

#include "libft.h"

void exit_program(t_prog *prog)
{
	SDL_DestroyTexture(prog->screen.texture);
	SDL_DestroyRenderer(prog->screen.renderer);
	SDL_DestroyWindow(prog->screen.window);
	ft_putendl("Exited the program successfully!");
	SDL_Quit();
}
