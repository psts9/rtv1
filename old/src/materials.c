#include "raytrace.h"

int		mat_lambertian(t_ray *ray, t_hitrecord *rec, t_vec3 *att, t_ray *result)
{
	t_vec3	temp;
	t_vec3	ran_p;

	ray->direction.z += 0.0;
	temp = vec_add(&rec->point, &rec->normal);
	ran_p = random_sphere_point();
	temp = vec_add(&temp, &ran_p);
	result->origin = rec->point;
	result->direction = vec_sub(&temp, &rec->point);
	*att = rec->material->albedo;
	return (1);
}

int		mat_metal(t_ray *ray, t_hitrecord *rec, t_vec3 *att, t_ray *result)
{
	t_vec3	temp;
	t_vec3	ran_p;
	double	d;

	temp = vec_unit(&ray->direction);
	temp = reflect_ray(&temp, &rec->normal);
	result->origin = rec->point;
	ran_p = random_sphere_point();
	ran_p = vec_mul_num(&ran_p, rec->material->fuzz);
	temp = vec_add(&temp, &ran_p);
	result->direction = temp;
	*att = rec->material->albedo;
	d = vec_dotproduct(&result->direction, &rec->normal);
	return (d > 0);
}

int		mat_dielectric(t_ray *ray, t_hitrecord *rec, t_vec3 *att, t_ray *result)
{
	t_vec3	temp;
	t_vec3	refracted;
	t_ray	final;
	double	d;
	int		i;

	temp = reflect_ray(&ray->direction, &rec->normal);
	*att = (t_vec3) { 1.0, 1.0, 1.0 };
	if (vec_dotproduct(&ray->direction, &rec->normal) > 0)
	{
		temp = vec_negative(&rec->normal);
		d = rec->material->refractiveness;
	}
	else
	{
		temp = rec->normal;
		d = 1.0 / rec->material->refractiveness;
	}
	i = refract_ray(&ray->direction, &temp, d, &refracted);
	final.origin = ray->origin;
	final.direction = refracted;
	*result = final;
	return (i);
}
