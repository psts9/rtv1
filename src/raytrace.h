#ifndef RAYTRACE_H
# define RAYTRACE_H

#include "rtv1.h"
#include "vector.h"
#include "object_list.h"

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

typedef struct	s_hitrecord
{
	double		d;
	t_vec3		point;
	t_vec3		normal;
	t_material	*material;
}				t_hitrecord;

void	raytrace(t_prog *prog, t_objlist *objlist);
t_vec3 	point_at_collision(t_ray *ray, double t);
t_vec3	random_sphere_point(void);
t_vec3	reflect_ray(t_vec3 *v, t_vec3 *normal);
int		refract_ray(t_vec3 *v, t_vec3 *normal, double n, t_vec3 *result);
int		mat_lambertian(t_ray *ray, t_hitrecord *rec, t_vec3 *att, t_ray *result);
int		mat_metal(t_ray *ray, t_hitrecord *rec, t_vec3 *att, t_ray *result);
int		mat_dielectric(t_ray *ray, t_hitrecord *rec, t_vec3 *att, t_ray *result);
int		hit_cylinder(t_ray *ray, double dist, t_hitrecord *rec, t_object *object);
int		hit_sphere(t_ray *ray, double dist, t_hitrecord *rec, t_object *object);

#endif
