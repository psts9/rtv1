#include <math.h>

#include "rtv1.h"
#include "draw.h"
#include "raytrace.h"

#include <stdio.h>

#define RANGE(x, min, max, a, b) (((b - a) * (x - min)) / (max - min) + a)

/*
	Sets up a quadractic equations where if any solution is found, the direction the ray is facing will end up in a collision with a sphere object
	We get the positive solution for the equation to find the intersection point
*/

double	hit_sphere(t_vec3 *origin, double radius, t_ray *ray)
{
	t_vec3	pos;
	double	a;
	double	b;
	double	c;
	double	d;
	
	pos = vec_sub(&ray->origin, origin);
	a = vec_dotproduct(&ray->direction, &ray->direction);
	b = 2.0 * vec_dotproduct(&pos, &ray->direction);
	c = vec_dotproduct(&pos, &pos) - radius * radius;
	d = b * b - 4.0 * a * c;
	if (d < 0.0)
		return (-1.0);
	else
		return ((-b - sqrt(d)) / (2.0 * a));
}



t_rgb	get_color(t_ray *ray)
{
	t_rgb	result;
	double	n;
	t_vec3	temp1;
	t_vec3	temp2;

	temp1 = (t_vec3) { 0, 0, -1 };
	n = hit_sphere(&temp1, 0.5, ray);
	if (n > 0.0)
	{
		temp2 = vec_mul_num(&ray->direction, n);
		temp2 = vec_add(&ray->origin, &temp2);
		temp2 = vec_sub(&temp2, &temp1);
		temp1 = vec_unit(&temp2);
		temp1 = vec_add_num(&temp1, 1.0);
		temp1 = vec_mul_num(&temp1, 0.5);
		result.r = temp1.x * 255;
		result.g = temp1.y * 255;
		result.b = temp1.z * 255;
	}
	else
		result = (t_rgb) { 0, 0, 0 };
	return (result);
}

void	get_ray_dir(t_ray *ray, int x, int y)
{
	ray->direction.x = RANGE(
		(float)x,
		0.0,
		(float)RES_X,
		(float)(-RES_X) / RES_Y,
		(float)RES_X / RES_Y
	);
	ray->direction.y = RANGE(
		(float)y,
		0.0,
		(float)RES_Y,
		1.0,
		-1.0
	);
	ray->direction.z = -1;
}

void	raytrace(t_prog *prog)
{
	int		x;
	int		y;
	t_ray	ray;

	y = 0;
	ray.origin = (t_vec3) { 0.0, 0.0, 0.0 };
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			get_ray_dir(&ray, x, y);
			put_pixel_rgb(get_color(&ray), x, y, &prog->screen);
			++x;
		}
		++y;
	}
}
