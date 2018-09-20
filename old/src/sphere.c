#include "raytrace.h"

int	hit_sphere(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	tpos;
	double	a;
	double	b;
	double	c;
	double	d;
	
	tpos = vec_sub(&ray->origin, &object->position);
	a = vec_dotproduct(&ray->direction, &ray->direction);
	b = vec_dotproduct(&tpos, &ray->direction);
	c = vec_dotproduct(&tpos, &tpos) - object->scale.x * object->scale.x;
	if (b * b - a * c > MIN_REFLECT_FLOAT)
	{
		d = (-b - sqrt(b * b - a * c)) / a;
		if (d < dist && d > MIN_REFLECT_FLOAT)
		{
			rec->d = d;
			rec->point = point_at_collision(ray, d);
			rec->normal = vec_sub(&rec->point, &object->position);
			rec->normal = vec_div_num(&rec->normal, object->scale.x);
			return (1);
		}
		d = (-b + sqrt(b * b - a * c)) / a;
		if (d < dist && d > MIN_REFLECT_FLOAT)
		{
			rec->d = d;
			rec->point = point_at_collision(ray, d);
			rec->normal = vec_sub(&rec->point, &object->position);
			rec->normal = vec_div_num(&rec->normal, object->scale.x);
			return (1);
		}
	}
	return (0);
}
