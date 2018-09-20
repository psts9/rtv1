#include "rtv1.h"
#include "raytrace.h"
#include "vector.h"

static t_hitrecord record_cylinder_hit(double d, t_ray *ray, t_object *object)
{
	t_hitrecord	rec;

	rec.d = d;
	rec.point = point_at_collision(ray, d);
	rec.normal = (t_vec3) { rec.point.x - object->position.x, 0, rec.point.z - object->position.z };
	rec.normal = vec_normalize(&rec.normal);
	return (rec);
}

int	hit_cylinder(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	pos;
	double	a;
	double	b;
	double	c;
	double	d;

	pos = vec_sub(&ray->origin, &object->position);
	a = pow(ray->direction.x, 2.0) + pow(ray->direction.z, 2.0);
	b = pos.x * ray->direction.x +
		pos.z * ray->direction.z;
	c = pow(pos.x, 2.0) + pow(pos.z, 2.0) - pow(object->radius, 2.0);
	if (b * b - a * c > EPSILON)
	{
		d = is_in_view(a, b, c, dist);
		if (d != -1.0)
		{
			*rec = record_cylinder_hit(d, ray, object);
			return (1);
		}
	}
	return (0);
}
