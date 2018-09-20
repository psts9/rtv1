#include <SDL2/SDL.h>
#include <stdio.h>

#include "libft.h"

void error_sdl(char *str)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(SDL_GetError());
	exit(EXIT_FAILURE);
}

void	perror_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

