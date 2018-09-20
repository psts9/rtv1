#include <math.h>

#include "rtv1.h"
#include "raytrace.h"
#include "vector.h"

static t_hitrecord	record_cone_hit(double d, t_ray *ray, t_object *object)
{
	t_hitrecord rec;
	float		r;

	rec.d = d;
	rec.point = point_at_collision(ray, d);
	r = sqrt(pow(rec.point.x - object->position.x, 2.0) + pow(rec.point.z - object->position.z, 2.0));
	t_vec3 temp;
	temp = (t_vec3) {rec.point.x - object->position.x, r * object->radius, rec.point.z - object->position.z };
	if (object->position.y < rec.point.y)
		temp.y = -temp.y;
		/*
	printf("%f\n", dir_y);
	rec.normal = (t_vec3) { rec.point.x - object->position.x, dir_y, rec.point.z - object->position.z };
	rec.normal = vec_normalize(&rec.normal);
	*/
	rec.normal = vec_normalize(&temp);
	return (rec);
}

int	hit_cone(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	pos;
	double	a;
	double	b;
	double	c;
	double	d;

	double	alpha = atan(object->radius);

	double cosalphasq = pow(cos(alpha), 2.0);
	double sinalphasq = pow(sin(alpha), 2.0);

	pos = vec_sub(&ray->origin, &object->position);
	a = cosalphasq * pow(ray->direction.x, 2.0) + cosalphasq * pow(ray->direction.z, 2.0) - sinalphasq * pow(ray->direction.y, 2.0);
	b = cosalphasq * ray->direction.x * pos.x + cosalphasq * ray->direction.z * pos.z - sinalphasq * ray->direction.y * pos.y;
	c = cosalphasq * pow(pos.x, 2.0) + cosalphasq * pow(pos.z, 2.0) - sinalphasq * pow(pos.y, 2.0);
	if (b * b - a * c > EPSILON)
	{
		d = is_in_view(a, b, c, dist);
		if (d != -1.0)
		{
			*rec = record_cone_hit(d, ray, object);
			return (1);
		}
	}
	return (0);
}
