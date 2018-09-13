#include "raytrace.h"

int	hit_plane(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	tpos;
	t_vec3	norm = (t_vec3) { 0, 1, 0 };
	double	a;
	double	b;
	double	d;
	t_vec3	temp;

	b = vec_dotproduct(&norm, &ray->direction);
	if (b == 0)
		return (0);
	tpos = vec_sub(&ray->origin, &object->position); // E
	temp = vec_sub(&object->position, &tpos); // Q - E
	a = vec_dotproduct(&norm, &temp);
	d = a / b;
	if (d <= 0.0 || d >= dist)
		return (0);
	rec->d = d;
	temp = vec_mul_num(&ray->direction, d);
	rec->point = vec_add(&temp, &tpos);
	rec->normal = vec_normalize(&norm);
	return (1);
}
