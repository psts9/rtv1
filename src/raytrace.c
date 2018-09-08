#include "rtv1.h"
#include "draw.h"
#include "time.h"

#include <stdio.h>

t_rgb get_color(int x, int y)
{
	t_rgb result;

	result.r = (float)x / RES_X * 255.0;
	result.g = (float)y / RES_Y * 255.0;
	result.b = 0.2 * 255.0;
	return (result);
}

void raytrace(t_prog *prog)
{
	int x;
	int y;
	t_rgb rgb;

	y = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			rgb = get_color(x, y);
			put_pixel_rgb(rgb, x, y, &prog->screen);
			++x;
		}
		++y;
	}
}
