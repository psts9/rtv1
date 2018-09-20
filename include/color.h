#ifndef COLOR_H
# define COLOR_H

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

t_rgb	change_brightness(t_rgb *color, double brightness);
t_rgb	apply_fog(t_rgb *color, t_rgb *fog_color, double amount);

#endif
