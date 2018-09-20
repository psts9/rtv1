#include "rtv1.h"
#include "raytrace.h"
#include "vector.h"

static t_hitrecord record_sphere_hit(double d, t_ray *ray, t_object *object)
{
	t_hitrecord rec;

	rec.d = d;
	rec.point = point_at_collision(ray, d);
	rec.normal = vec_sub(&rec.point, &object->position);
	rec.normal = vec_div_num(&rec.normal, object->radius);
	return (rec);
}

int	hit_sphere(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	pos;
	double	a;
	double	b;
	double	c;
	double	d;

	pos = vec_sub(&ray->origin, &object->position);
	a = vec_dotproduct(&ray->direction, &ray->direction);
	b = vec_dotproduct(&pos, &ray->direction);
	c = vec_dotproduct(&pos, &pos) - object->radius * object->radius;
	if (b * b - a * c > EPSILON)
	{
		d = is_in_view(a, b, c, dist);
		if (d != -1.0)
		{
			*rec = record_sphere_hit(d, ray, object);
			return (1);
		}
	}
	return (0);
}
