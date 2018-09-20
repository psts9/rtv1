#include "raytrace.h"

int	hit_plane(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	tpos;
	t_vec3	norm = (t_vec3)
	{
		cos(object->rotation.x * DEG_TO_RAD) * cos(object->rotation.z * DEG_TO_RAD),
		sin(object->rotation.z * DEG_TO_RAD),
		sin(object->rotation.x * DEG_TO_RAD) * cos(object->rotation.z * DEG_TO_RAD)
	};
//	t_vec3	norm = (t_vec3) { 0.0, 1.0, 1.0 };
	double	a;
	double	b;
	double	d;
	t_vec3	temp;

	norm = vec_normalize(&norm);
	b = vec_dotproduct(&norm, &ray->direction);
	if (b == 0.0)
		return (0);
	tpos = vec_sub(&ray->origin, &object->position); // E
	temp = vec_sub(&object->position, &tpos); // Q - E
	a = vec_dotproduct(&norm, &temp);
//	printf("%f, %f, %f\n", norm.x, norm.y, norm.z);
	d = a / b;
	if (d <= 0.0 || d >= dist)
		return (0);
	rec->d = d;
	temp = vec_mul_num(&ray->direction, d);
	rec->point = vec_add(&temp, &tpos);
	rec->normal = vec_normalize(&norm);
	return (1);
}
