/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_utility_math.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 03:41:30 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 03:41:31 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "rtv1.h"
#include "raytrace.h"
#include "camera.h"

t_vec3	point_at_collision(t_ray *ray, double t)
{
	t_vec3	result;

	result = vec_mul_num(&ray->direction, t);
	result = vec_add(&ray->origin, &result);
	return (result);
}

double	is_in_view(double a, double b, double c, double dist)
{
	double d;

	d = (-b - sqrt(b * b - a * c)) / a;
	if (d < dist && d > EPSILON)
		return (d);
	d = (-b + sqrt(b * b - a * c)) / a;
	if (d < dist && d > EPSILON)
		return (d);
	return (-1.0);
}

double	clamp(double n, double min, double max)
{
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}

double	deg_to_rad(double n)
{
	return (n * DEG_TO_RAD);
}

t_ray	get_ray_dir(t_camera *cam, double x, double y, t_screen *screen)
{
	t_ray	result;
	double	aspect;

	aspect = (double)screen->width / (double)screen->height;
	result.origin = cam->origin;
	result.direction.x = (2.0 * ((x + 0.5) / (double)screen->width) - 1.0)
							* aspect;
	result.direction.y = (1.0 - 2.0 * ((y + 0.5) / (double)screen->height));
	result.direction.z = -1.0;
	result.direction = vec_rotate(&result.direction, &cam->direction);
	result.direction = vec_normalize(&result.direction);
	return (result);
}
