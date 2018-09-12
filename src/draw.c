#include <SDL2/SDL.h>

#include "rtv1.h"
#include "draw.h"

void	update_screen(t_screen *screen)
{
	SDL_UpdateTexture(screen->texture, NULL, screen->pixels, RES_X * sizeof(uint32_t));
	SDL_RenderClear(screen->renderer);
	SDL_RenderCopy(screen->renderer, screen->texture, 0, 0);
	SDL_RenderPresent(screen->renderer);
}

void put_pixel(int color, int x, int y, t_screen *screen)
{
	screen->pixels[x + y * RES_X] = color;
}

void put_pixel_rgb(t_rgb rgb, int x, int y, t_screen *screen)
{
	int color;

	color = rgb.r;
	color = (color << 8) + rgb.g;
	color = (color << 8) + rgb.b;
	put_pixel(color, x, y, screen);
}
