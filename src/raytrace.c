#include <math.h>
#include <stdio.h>

#include "rtv1.h"
#include "draw.h"
#include "object_list.h"
#include "raytrace.h"
#include "events.h"
#include "time.h"
#include "camera.h"
#include "matrix.h"

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
		apply_brightspot(&result, RANGE(b, 0.0, 1.0, 0.0, 0.3));
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
	double	aspect;
	
	aspect = (double)screen->width / (double)screen->height;
	result.origin = cam->origin;
	result.direction.x = (2.0 * ((x + 0.5) / (double)screen->width) - 1.0) * aspect;
	result.direction.y = (1.0 - 2.0 * ((y + 0.5) / (double)screen->height));
	result.direction.z = -1.0;
	result.direction = vec_rotate(&result.direction, &cam->direction);
	result.direction = vec_normalize(&result.direction);
	return (result);
}

// horizontal = ratio * 2, 0, 0
// vertical = 0, -2, 0

t_camera init_camera(t_vec3 *origin, t_vec3 *direction, t_screen *screen)
{
	// half_height = 1
	// half_width = aspect ratio
	t_camera	cam;
	
	cam.origin = *origin;
	cam.horizontal = (t_vec3) { (double)screen->width / (double)screen->height * 2, 0.0, 0.0 };
	cam.vertical = (t_vec3) { 0.0, -2.0, 0.0 };
	cam.start_point = cam.origin;
	cam.start_point.x -= cam.horizontal.x / 2.0;
	cam.start_point.y -= cam.vertical.y / 2.0;
	cam.start_point.z = -1.0;
	cam.direction = *direction;
	direction = NULL;
	return (cam);
}

void	raytrace(t_prog *prog, t_objlist *objlist)
{
	int		x;
	int		y;
	t_ray	ray;
	t_rgb	color;
	t_camera cam;

//	t_vec3	origin = (t_vec3) { 0.0, 0.0, 0.0 };
//	double mat[4][4];

	static double test = 0.0;

	t_vec3	cam_origin		= (t_vec3) {  0.0,  0.0,  0.0 };
	t_vec3	cam_direction	= (t_vec3) { test, test, test };

	printf("%f\n", test++);

	cam = init_camera(&cam_origin, &cam_direction, &prog->screen);
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
	//	update_screen(&prog->screen);
	//	do_events_running(prog);
		++y;
	}
	update_screen(&prog->screen);
	do_events_running(prog);
}
