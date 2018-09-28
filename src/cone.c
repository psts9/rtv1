/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:37:03 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/27 23:39:44 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "rtv1.h"
#include "raytrace.h"
#include "vector.h"

static t_vec3		get_cone_abc(t_ray *ray, t_object *object)
{
	t_vec3	result;
	t_vec3	unit_vector;
	t_vec3	relative_position;
	double	alphasq;

	alphasq = 1 + pow(atan(object->radius), 2.0);
	unit_vector = (t_vec3) { 0.0, 1.0, 0.0 };
	unit_vector = vec_rotate(&unit_vector, &object->rotation);
	relative_position = vec_sub(&ray->origin, &object->position);
	result.x = vec_dotproduct(&ray->direction, &ray->direction) -
				alphasq *
				pow(vec_dotproduct(&ray->direction, &unit_vector), 2.0);
	result.y = vec_dotproduct(&ray->direction, &relative_position) -
				alphasq *
				vec_dotproduct(&ray->direction, &unit_vector) *
				vec_dotproduct(&relative_position, &unit_vector);
	result.z = vec_dotproduct(&relative_position, &relative_position) -
				alphasq *
				pow(vec_dotproduct(&relative_position, &unit_vector), 2.0);
	return (result);
}

static t_hitrecord	record_cone_hit(double d, t_ray *ray, t_object *object)
{
	double		m;
	t_vec3		temp1;
	t_vec3		temp2;
	t_hitrecord	rec;

	rec.d = d;
	rec.point = point_at_collision(ray, d);
	temp1 = (t_vec3) { 0.0, 1.0, 0.0 };
	temp1 = vec_rotate(&temp1, &object->rotation);
	temp2 = vec_sub(&ray->origin, &object->position);
	m = vec_dotproduct(&ray->direction, &temp1) * d +
		vec_dotproduct(&temp2, &temp1);
	temp2 = vec_sub(&rec.point, &object->position);
	temp1 = vec_mul_num(&temp1, (1 + pow(atan(object->radius), 2.0)) * m);
	temp1 = vec_sub(&temp2, &temp1);
	rec.d = d;
	rec.point = point_at_collision(ray, d);
	rec.normal = vec_normalize(&temp1);
	rec.albedo = object->albedo;
	return (rec);
}

int					hit_cone(t_ray *ray, double dist,
							t_hitrecord *rec, t_object *object)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec3	temp;

	temp = get_cone_abc(ray, object);
	a = temp.x;
	b = temp.y;
	c = temp.z;
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
