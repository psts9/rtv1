#include <stdlib.h>
#include <math.h>

#include "vector.h"
#include "raytrace.h"

t_vec3 point_at_collision(t_ray *ray, double t)
{
	t_vec3	result;

	result = vec_mul_num(&ray->direction, t);
	result = vec_add(&ray->origin, &result);
	return (result);
}

t_vec3 random_sphere_point(void)
{
	t_vec3	point;
	t_vec3	temp1;
	t_vec3	temp2;

	temp1 = (t_vec3) { 1, 1, 1 };
	temp2 = (t_vec3) { drand48(), drand48(), drand48() };
	point = vec_mul_num(&temp2, 2.0);
	point = vec_sub(&point, &temp1);
	while (vec_squaredlength(&point) >= 1.0)
	{
		temp2 = (t_vec3) { drand48(), drand48(), drand48() };
		point = vec_mul_num(&temp2, 2.0);
		point = vec_sub(&point, &temp1);
	}
	return (point);
}

t_vec3 reflect_ray(t_vec3 *v, t_vec3 *normal)
{
	t_vec3	result;
	double	d;

	d = 2 * vec_dotproduct(v, normal);
	result = vec_mul_num(normal, d);
	result = vec_sub(v, &result);
	return (result);
}

int		refract_ray(t_vec3 *v, t_vec3 *normal, double n, t_vec3 *result)
{
	t_vec3	unit_vector;
	t_vec3	temp;
	double	dot;
	double	d;

	unit_vector = vec_unit(v);
	dot = vec_dotproduct(&unit_vector, normal);
	d = 1.0 - pow(n, 2.0) * (1 - pow(dot, 2.0));
	if (d > 0)
	{
		temp = vec_mul_num(normal, dot);
		unit_vector = vec_sub(&unit_vector, &temp);
		unit_vector = vec_mul_num(&unit_vector, n);
		temp = vec_mul_num(normal, sqrt(d));
		*result = vec_sub(&unit_vector, &temp);
		return (1);
	}
	return (0);
}
