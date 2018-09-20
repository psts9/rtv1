#include <math.h>
#include <stdio.h>

#include "rtv1.h"
#include "draw.h"
#include "object_list.h"
#include "raytrace.h"
#include "events.h"
#include "time.h"
#include "camera.h"

typedef int (*t_hitfunc)(t_ray *, double, t_hitrecord *, t_object *object);
t_hitfunc hit_funcs[4] = { hit_sphere, hit_cylinder, hit_cone, hit_plane };

int		hit_objlist(t_ray *ray, double dist, t_hitrecord *rec, t_objlist *objlist)
{
	t_hitrecord	temp_rec;
	int			hit;

	hit = 0;
	while (objlist)
	{
		if (hit_funcs[objlist->object.type](ray, dist, &temp_rec, &objlist->object))
		{
			hit = 1;
			dist = temp_rec.d;
			temp_rec.albedo = objlist->object.albedo;
			*rec = temp_rec;
		}
		objlist = objlist->next;
	}
	return (hit);
}

double	get_brightness(t_vec3 *v)
{
	double	brightness;
	t_vec3	light_dir = (t_vec3) { -1.0,-1.0,-1.0 };

	light_dir = vec_negative(&light_dir);
	light_dir = vec_normalize(&light_dir);
	brightness = vec_dotproduct(v, &light_dir);
	if (brightness > 0.0)
		return ((brightness + DS_SHADE) / (1.0 + DS_SHADE));
	return (DS_SHADE);
}

void	apply_brightspot(t_rgb *col, double amount)
{
	t_rgb	brightspot_color = { 255, 255, 255 };

	*col = apply_fog(col, &brightspot_color, amount);
}

t_rgb	get_color(t_ray *ray, t_objlist *objlist)
{
	t_rgb		result;
	t_hitrecord	rec;

	if (hit_objlist(ray, DBL_MAX, &rec, objlist))
	{
		double b = get_brightness(&rec.normal);
		result.r = pow(rec.albedo.x * 255, GAMMA);
		result.g = pow(rec.albedo.y * 255, GAMMA);
		result.b = pow(rec.albedo.z * 255, GAMMA);
		if (b > 0.95)
			apply_brightspot(&result, RANGE(b, 0.95, 1.0, 0.0, 0.2));
		if (rec.d < VIEWING_DIST)
			result = change_brightness(&result, 1.0 - (rec.d / VIEWING_DIST));
		else
			result = change_brightness(&result, 0.0);
		result = change_brightness(&result, b);
	}
	else
	{
		result = (t_rgb) { 0, 0, 0 };
	}
	return (result);
}

t_ray	get_ray_dir(t_camera *cam, double x, double y, t_screen *screen)
{
	t_ray	result;
	t_vec3	temp;

	temp = vec_mul_num(&cam->horizontal, screen->width / x);
	result.origin = cam->origin;
	result.direction = vec_add(&cam->start_point, &temp);
	temp = vec_mul_num(&cam->vertical, screen->height / y);
	result.direction = vec_add(&cam->start_point, &temp);
	result.direction = vec_sub(&result.direction, &cam->origin);
	return (result);
}

t_camera init_camera(t_vec3 *origin, t_vec3 *direction, t_vec3 *up, t_screen *screen)
{
	t_camera	cam;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
	t_vec3		temp;

	cam.origin = *origin;
	w = vec_sub(origin, direction);
	w = vec_normalize(&w);
	u = vec_crossproduct(up, &w);
	u = vec_normalize(&u);
	v = vec_crossproduct(&w, &u);
	temp = vec_mul_num(&u, screen->width / screen->height * 2);
	cam.start_point = vec_sub(origin, &temp);
	temp = vec_mul_num(&v, -1.0);
	cam.start_point = vec_sub(&cam.start_point, &temp);
	cam.start_point = vec_sub(&cam.start_point, &w);
	cam.horizontal = vec_mul_num(&u, screen->width / screen->height * 2.0);
	cam.vertical = vec_mul_num(&v, -2.0);
	return (cam);
}

void	raytrace(t_prog *prog, t_objlist *objlist)
{
	int		x;
	int		y;
	t_ray	ray;
	t_rgb	color;
	t_camera cam;

	t_vec3	cam_origin = (t_vec3) { 0.0, 0.0, 0.0 };
	t_vec3	cam_direction = (t_vec3) { 0.0, 0.0, -1.0 };
	t_vec3	cam_up = (t_vec3) { 0.0, 1.0, 0.0 };

	cam = init_camera(&cam_origin, &cam_direction, &cam_up, &prog->screen);
	printf("%f %f %f\n", cam.vertical.x, cam.vertical.y, cam.vertical.z);
	y = 0;
	while (y < prog->screen.height)
	{
		x = 0;
		while (x < prog->screen.width)
		{
			ray = get_ray_dir(&cam, x, y, &prog->screen);
			color = get_color(&ray, objlist);
			put_pixel_rgb(color, x, y, &prog->screen);
			++x;
		}
		update_screen(&prog->screen);
		do_events_running(prog);
		++y;
	}
}
