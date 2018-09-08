
#include "rtv1.h"
#include "draw.h"

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
