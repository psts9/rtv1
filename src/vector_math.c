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

double	vec_squaredlength(t_vec3 *v)
{
	return
	(
		v->x * v->x +
		v->y * v->y +
		v->z * v->z
	);
}

double	vec_length(t_vec3 *v)
{
	return (sqrt(vec_squaredlength(v)));
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

t_vec3	vec_normalize(t_vec3 *v)
{
	t_vec3	result;
	double	length;

	length = vec_length(v);
	result = vec_div_num(v, length);
	return (result);
}

t_vec3	vec_negative(t_vec3 *v)
{
	return ((t_vec3)
	{
		-(v->x),
		-(v->y),
		-(v->z)
	});
}

t_vec3	vec_crossproduct(t_vec3 *v1, t_vec3 *v2)
{
	return ((t_vec3)
	{
		v1->y * v2->z - v1->z * v2->y,
	   -v1->x * v2->z - v1->z * v2->x,
		v1->x * v2->y - v1->y * v2->x
	});
}
