#include "vector.h"
#include "rtv1.h"
#include "raytrace.h"

t_vec3	point_at_collision(t_ray *ray, double t)
{
	t_vec3	result;

	result = vec_mul_num(&ray->direction, t);
	result = vec_add(&ray->origin, &result);
	return (result);
}

double	is_in_view(double a, double b, double c, double dist)
{
	double d;

	d = (-b - sqrt(b * b - a * c)) / a;
	if (d < dist && d > EPSILON)
		return (d);
	d = (-b + sqrt(b * b - a * c)) / a;
	if (d < dist && d > EPSILON)
		return (d);
	return (-1.0);
}
