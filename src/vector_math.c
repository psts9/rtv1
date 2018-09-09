#include <math.h>

#include "vector.h"

t_vec3	vec_add(t_vec3 *v1, t_vec3 *v2)
{
	return ((t_vec3)
	{ 
		v1->x + v2->x, 
		v1->y + v2->y,
		v1->z + v2->z
	});
}

t_vec3	vec_sub(t_vec3 *v1, t_vec3 *v2)
{
	return ((t_vec3)
	{
		v1->x - v2->x,
		v1->y - v2->y,
		v1->z - v2->z
	});
}

t_vec3	vec_mul(t_vec3 *v1, t_vec3 *v2)
{
	return ((t_vec3)
	{
		v1->x * v2->x,
		v1->y * v2->y,
		v1->z * v2->z
	});
}

t_vec3	vec_div(t_vec3 *v1, t_vec3 *v2)
{
	return ((t_vec3)
	{
		v1->x / v2->x,
		v1->y / v2->y,
		v1->z / v2->z
	});
}

t_vec3	vec_add_num(t_vec3 *v, double n)
{
	return ((t_vec3)
	{
		v->x + n,
		v->y + n,
		v->z + n
	});
}

t_vec3	vec_sub_num(t_vec3 *v, double n)
{
	return ((t_vec3)
	{
		v->x - n,
		v->y - n,
		v->z - n
	});
}

t_vec3	vec_mul_num(t_vec3 *v, double n)
{
	return ((t_vec3)
	{
		v->x * n,
		v->y * n,
		v->z * n
	});
}

t_vec3	vec_div_num(t_vec3 *v, double n)
{
	return ((t_vec3)
	{
		v->x / n,
		v->y / n,
		v->z / n
	});
}

double	vec_length(t_vec3 *v)
{
	return
	(sqrt(
		v->x * v->x + 
		v->y * v->y +
		v->z * v->z
	));
}

double	vec_dotproduct(t_vec3 *v1, t_vec3 *v2)
{
	return
	(
		v1->x * v2->x + 
		v1->y * v2->y + 
		v1->z * v2->z
	);
}

t_vec3	vec_unit(t_vec3 *v)
{
	double	length;

	length = vec_length(v);
	return (vec_div_num(v, length));
}
