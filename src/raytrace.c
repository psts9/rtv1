/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:15:32 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 02:15:38 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "rtv1.h"
#include "draw.h"
#include "object_list.h"
#include "raytrace.h"
#include "events.h"
#include "time.h"
#include "camera.h"
#include "light_list.h"
#include "scene.h"

typedef int	(*t_hitfunc)(t_ray *, double, t_hitrecord *, t_object *object);
t_hitfunc g_hit_funcs[4] = { hit_sphere, hit_cylinder, hit_cone, hit_plane };

int		hit_objlist(t_ray *ray, double dist,
		t_hitrecord *rec, t_objlist *objlist)
{
	t_hitrecord	temp_rec;
	int			hit;

	hit = 0;
	while (objlist)
	{
		if (g_hit_funcs[objlist->object.type](ray, dist,
							&temp_rec, &objlist->object))
		{
			hit = 1;
			dist = temp_rec.d;
			*rec = temp_rec;
		}
		objlist = objlist->next;
	}
	return (hit);
}

t_rgb	get_color(t_ray *ray, t_scene *scene)
{
	t_rgb		result;
	t_hitrecord	rec;
	t_vec3		temp;

	if (hit_objlist(ray, DBL_MAX, &rec, scene->objlist))
	{
		temp = get_shade(&rec, scene->lightlist, scene->objlist);
		result = (t_rgb) {
			pow(clamp(temp.x, 0.0, 1.0) * 255, GAMMA),
			pow(clamp(temp.y, 0.0, 1.0) * 255, GAMMA),
			pow(clamp(temp.z, 0.0, 1.0) * 255, GAMMA)
		};
	}
	else
	{
		result = (t_rgb) { 0, 0, 0 };
	}
	return (result);
}

void	raytrace(t_prog *prog, t_scene *scene)
{
	int			x;
	int			y;
	t_ray		ray;
	t_rgb		color;
	t_camera	cam;

	cam.origin = scene->cam.origin;
	cam.direction = scene->cam.direction;
	y = 0;
	while (y < prog->screen.height)
	{
		x = 0;
		while (x < prog->screen.width)
		{
			ray = get_ray_dir(&cam, x, y, &prog->screen);
			color = get_color(&ray, scene);
			put_pixel_rgb(color, x, y, &prog->screen);
			++x;
		}
		update_screen(&prog->screen);
		do_events_running(prog);
		++y;
	}
}
