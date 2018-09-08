#include <SDL2/SDL.h>

#include "libft.h"

void error_sdl(char *str)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(SDL_GetError());
	exit(-1);
}
