/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:09:31 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:09:45 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "rtv1.h"
# include "vector.h"
# include "object_list.h"
# include "scene.h"
# include "camera.h"

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

struct s_scene	asdf;
void			raytrace(t_prog *prog, t_scene *scene);
t_vec3			point_at_collision(t_ray *ray, double t);
double			is_in_view(double a, double b, double c, double dist);
double			deg_to_rad(double n);
t_ray			get_ray_dir(t_camera *cam,
				double x, double y, t_screen *screen);
double			clamp(double n, double min, double max);
t_vec3			get_shade(t_hitrecord *rec, t_lightlist *lightlist,
				t_objlist *objlist);
int				hit_objlist(t_ray *ray, double dist,
				t_hitrecord *rec, t_objlist *objlist);
int				hit_sphere(t_ray *ray, double dist,
				t_hitrecord *rec, t_object *object);
int				hit_cylinder(t_ray *ray, double dist,
				t_hitrecord *rec, t_object *object);
int				hit_cone(t_ray *ray, double dist,
				t_hitrecord *rec, t_object *object);
int				hit_plane(t_ray *ray, double dist,
				t_hitrecord *rec, t_object *object);

#endif
