#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "rtv1.h"
# include "vector.h"
# include "object_list.h"

# define RANGE(x, min, max, a, b) (((b - a) * (x - min)) / (max - min) + a)

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
	t_vec3		albedo;
}				t_hitrecord;

void	raytrace(t_prog *prog, t_objlist *objlist);
t_vec3	point_at_collision(t_ray *ray, double t);
double	is_in_view(double a, double b, double c, double dist);

int		hit_sphere(t_ray *ray, double dist, t_hitrecord *rec, t_object *object);
int		hit_cylinder(t_ray *ray, double dist, t_hitrecord *rec, t_object *object);
int		hit_cone(t_ray *ray, double dist, t_hitrecord *rec, t_object *object);
int		hit_plane(t_ray *ray, double dist, t_hitrecord *rec, t_object *object);

#endif
