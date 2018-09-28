/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:13:59 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 02:15:25 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace.h"

static t_hitrecord	record_plane_hit(double d, t_ray *ray,
					t_object *object, t_vec3 *surface_normal)
{
	t_hitrecord	rec;

	rec.d = d;
	rec.point = point_at_collision(ray, d);
	rec.normal = *surface_normal;
	rec.albedo = object->albedo;
	return (rec);
}

int					hit_plane(t_ray *ray, double dist,
					t_hitrecord *rec, t_object *object)
{
	t_vec3	surface_normal;
	t_vec3	relative_position;
	double	a;
	double	b;
	double	d;

	surface_normal = (t_vec3) { 0.0, 1.0, 0.0 };
	surface_normal = vec_rotate(&surface_normal, &object->rotation);
	relative_position = vec_sub(&ray->origin, &object->position);
	a = -(vec_dotproduct(&relative_position, &surface_normal));
	b = vec_dotproduct(&ray->direction, &surface_normal);
	if (b < EPSILON && b >= 0.0)
		return (0);
	d = a / b;
	if (d < EPSILON || d > dist)
		return (0);
	*rec = record_plane_hit(d, ray, object, &surface_normal);
	if (b > 0.0)
		rec->normal = vec_negative(&rec->normal);
	return (1);
}
