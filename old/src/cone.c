#include "raytrace.h"

int hit_cone(t_ray *ray, double dist, t_hitrecord *rec, t_object *object)
{
	t_vec3	tpos;
	double	a;
	double	b;
	double	c;
	double	d;
	double 	z;
	double	y_min;
	double	y_max;
	double	cosalphsq;
	double	sinalphsq;
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p;

	p1 = (t_vec3) { object->position.x + object->scale.x, object->position.y, object->position.z };
	p2 = (t_vec3) { object->position.x, object->position.y + object->scale.y, object->position.z };
	p1 = vec_sub(&p1, &p2);
	double len = vec_length(&p1);
	double cosalphasq = object->scale.y / len;
	double sinalphasq = object->scale.x / len;
	tpos = vec_sub(&ray->origin, &object->position);
	/*
	a =  pow(ray->direction.x, 2.0) + pow(ray->direction.z, 2.0);
	a -= pow(ray->direction.y, 2.0);
	b =  2 * tpos.x * ray->direction.x + 2.0 * tpos.z * ray->direction.z;
	b -= 2 * tpos.y * ray->direction.y;
	c =  pow(tpos.x, 2.0) + pow(tpos.z, 2.0) - pow(tpos.y, 2.0);
	*/
	a = cosalphasq * pow(ray->direction.x, 2.0) + cosalphasq * pow(ray->direction.z, 2.0) - sinalphasq * pow(ray->direction.y, 2.0);
	b = cosalphasq * ray->direction.x * tpos.x + cosalphasq * ray->direction.z * tpos.z - sinalphasq * ray->direction.y * tpos.y;
	c = cosalphasq * pow(tpos.x, 2.0) + cosalphasq * pow(tpos.z, 2.0) - sinalphasq * pow(tpos.y, 2.0);
	if (b * b - a * c > MIN_REFLECT_FLOAT)
	{
		double y; 
		d = (-b - sqrt(b * b - a * c)) / (a);
		if (d < dist && d > MIN_REFLECT_FLOAT)
		{
			rec->d = d;
			rec->point = point_at_collision(ray, d);
			y = tpos.y + rec->point.y;
				t_vec3	tmp3 = vec_sub(&rec->point, &object->position);
				tmp3.y = 0;
				tmp3 = vec_normalize(&tmp3);

				rec->normal.x = tmp3.x * object->scale.y / object->scale.x;
				rec->normal.z = tmp3.z * object->scale.y / object->scale.x;
				rec->normal.y = object->scale.x / object->scale.y;
				return (1);
		}
		d = (-b + sqrt(b * b - a * c)) / (a);
		if (d < dist && d > MIN_REFLECT_FLOAT)
		{
			rec->d = d;
			rec->point = point_at_collision(ray, d);
			y = tpos.y + rec->point.y;
				t_vec3	tmp3 = vec_sub(&rec->point, &object->position);
				tmp3.y = 0;
				tmp3 = vec_normalize(&tmp3);

				rec->normal.x = tmp3.x * object->scale.y / object->scale.x;
				rec->normal.z = tmp3.z * object->scale.y / object->scale.x;
				rec->normal.y = object->scale.x / object->scale.y;
				return (1);
		}
	}
	return (0);
}
