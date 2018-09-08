#ifndef DRAW_H
# define DRAW_H

# include "rtv1.h"

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

void				put_pixel(int color, int x, int y, t_screen *screen);
void				put_pixel_rgb(t_rgb rgb, int x, int y, t_screen *screen);

#endif
