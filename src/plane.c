#include "raytrace.h"

int	hit_plane(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	pos;
	t_vec3	norm = (t_vec3) { 0.0, 1.0, 0.0 };
	t_vec3	temp;
	double	a;
	double	b;
	double	d;

	b = vec_dotproduct(&norm, &ray->direction);
	if (b == 0.0)
		return (0);
	pos = vec_sub(&ray->origin, &object->position);
	temp = vec_sub(&object->position, &pos);
	a = vec_dotproduct(&norm, &temp);
	d = a / b;
	if (d <= 0.0 || d >= dist)
		return (0);
	rec->d = d;
	temp = vec_mul_num(&ray->direction, d);
	rec->point = vec_add(&temp, &pos);
	rec->normal = vec_normalize(&norm);
	if (pos.y < 0.0)
		rec->normal = vec_negative(&rec->normal);
	return (1);
}
