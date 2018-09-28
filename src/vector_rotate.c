/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 03:57:58 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 03:58:36 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "raytrace.h"

static t_vec3	vec_rotate_x(t_vec3 *v, double rot)
{
	t_vec3	result;

	result.x = v->x;
	result.y = v->y * cos(deg_to_rad(rot)) - v->z * sin(deg_to_rad(rot));
	result.z = v->y * sin(deg_to_rad(rot)) + v->z * cos(deg_to_rad(rot));
	return (result);
}

static t_vec3	vec_rotate_y(t_vec3 *v, double rot)
{
	t_vec3	result;

	result.x = v->x * cos(deg_to_rad(rot)) + v->z * sin(deg_to_rad(rot));
	result.y = v->y;
	result.z = -v->x * sin(deg_to_rad(rot)) + v->z * cos(deg_to_rad(rot));
	return (result);
}

static t_vec3	vec_rotate_z(t_vec3 *v, double rot)
{
	t_vec3	result;

	result.x = v->x * cos(deg_to_rad(rot)) - v->y * sin(deg_to_rad(rot));
	result.y = v->x * sin(deg_to_rad(rot)) + v->y * cos(deg_to_rad(rot));
	result.z = v->z;
	return (result);
}

t_vec3			vec_rotate(t_vec3 *v, t_vec3 *r)
{
	t_vec3	result;

	result = *v;
	result = vec_rotate_x(&result, r->x);
	result = vec_rotate_y(&result, r->y);
	result = vec_rotate_z(&result, r->z);
	return (result);
}
