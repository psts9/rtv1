/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 03:42:32 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 03:43:19 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "rtv1.h"
#include "raytrace.h"
#include "object_list.h"

static double	get_light_info(t_hitrecord *rec, t_light *light,
							t_vec3 *intensity, t_vec3 *light_dir)
{
	t_vec3	unit_vector;
	double	length;
	double	dist;

	dist = DBL_MAX;
	if (light->type == POINT)
	{
		*light_dir = vec_sub(&rec->point, &light->position);
		length = vec_dotproduct(light_dir, light_dir);
		dist = sqrt(length);
		*light_dir = vec_normalize(light_dir);
		*intensity = vec_mul_num(&light->albedo, light->intensity);
		*intensity = vec_div_num(intensity, 4.0 * M_PI * length);
	}
	else if (light->type == DIRECTIONAL)
	{
		unit_vector = (t_vec3) { 0.0, -1.0, 0.0 };
		*light_dir = vec_rotate(&unit_vector, &light->rotation);
		*intensity = vec_mul_num(&light->albedo, light->intensity);
	}
	return (dist);
}

static double	get_brightness(t_vec3 *v, t_vec3 *light)
{
	double	brightness;
	t_vec3	light_dir;

	light_dir = *light;
	light_dir = vec_normalize(&light_dir);
	brightness = vec_dotproduct(v, &light_dir);
	if (brightness > 0.0)
		return (brightness + DS_SHADE) / (1.0 + DS_SHADE);
	return (DS_SHADE);
}

static t_vec3	shade_result(t_hitrecord *rec, t_vec3 *intensity,
		t_ray *shadow_ray, t_vec3 *prev_result)
{
	t_vec3	temp;
	t_vec3	result;

	temp = vec_mul(&rec->albedo, intensity);
	temp = vec_mul_num(&temp, get_brightness(&rec->normal,
								&shadow_ray->direction));
	result = vec_add(prev_result, &temp);
	return (result);
}

t_vec3			get_shade(t_hitrecord *rec, t_lightlist *lightlist,
												t_objlist *objlist)
{
	t_ray		shadow_ray;
	t_vec3		light_dir;
	t_hitrecord	shadow_rec;
	t_ray		result;
	double		dist;

	result.origin = (t_vec3) { 0.0, 0.0, 0.0 };
	while (lightlist)
	{
		dist = get_light_info(rec, &lightlist->light,
						&result.direction, &light_dir);
		shadow_ray.origin = rec->point;
		shadow_ray.direction = vec_negative(&light_dir);
		if (!hit_objlist(&shadow_ray, dist, &shadow_rec, objlist))
			result.origin = shade_result(rec, &result.direction,
									&shadow_ray, &result.origin);
		lightlist = lightlist->next;
	}
	return (result.origin);
}
