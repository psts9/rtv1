#include "raytrace.h"

int hit_cylinder(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	tpos;
	double	a;
	double	b;
	double	c;
	double	d;
	double	z;
	double 	y_min;
	double	y_max;

	tpos = vec_sub(&ray->origin, &object->position);
	a = pow(ray->direction.x, 2) + pow(ray->direction.z, 2);
	b =  2.0 * tpos.x * ray->direction.x;
	b += 2.0 * tpos.z * ray->direction.z;
	c = pow(tpos.x, 2) + pow(tpos.z, 2) - object->scale.x * object->scale.x;

	if (b * b - 4 * a * c > MIN_REFLECT_FLOAT)
	{
		y_min = ray->origin.y - tpos.y - object->scale.y / 2.0;
		y_max = y_min + object->scale.y;
		d = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		z = tpos.y + ray->direction.y * d;
		if (d < dist && d > MIN_REFLECT_FLOAT)
		{
				rec->d = d;
				rec->point = point_at_collision(ray, d);
				rec->normal = (t_vec3) { rec->point.x - object->position.x, 0, rec->point.z - object->position.z };
				rec->normal = vec_normalize(&rec->normal);
				return (1);
		}
		d = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		z = tpos.y + ray->direction.y * d;
		if (d < dist && d > MIN_REFLECT_FLOAT)
		{
				rec->d = d;
				rec->point = point_at_collision(ray, d);
				rec->normal = (t_vec3) { rec->point.x - object->position.x, 0, rec->point.z - object->position.z };
				rec->normal = vec_normalize(&rec->normal);
				return (1);
		}
	}
	return (0);
}
