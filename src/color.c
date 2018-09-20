#include "color.h"

t_rgb	change_brightness(t_rgb *color, double brightness)
{
	t_rgb result;

	result.r = color->r * brightness;
	result.g = color->g * brightness;
	result.b = color->b * brightness;
	return (result);
}

t_rgb	apply_fog(t_rgb *color, t_rgb *fog_color, double amount)
{
	t_rgb result;

	result.r = (1.0 - amount) * color->r + amount * fog_color->r;
	result.g = (1.0 - amount) * color->g + amount * fog_color->g;
	result.b = (1.0 - amount) * color->b + amount * fog_color->b;
	return (result);
}
