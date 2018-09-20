#include <math.h>

#include "rtv1.h"
#include "draw.h"
#include "object_list.h"
#include "raytrace.h"

#include <stdio.h>
#include <float.h>

#define RANGE(x, min, max, a, b) (((b - a) * (x - min)) / (max - min) + a)
#define MIN_DIST 0.0

/*
	Sets up a quadractic equations where if any solution is found, the direction the ray is facing will end up in a collision with a sphere object
	We get the positive solution for the equation to find the intersection point
*/
/*
double	hit_sphere(t_vec3 *origin, double radius, t_ray *ray)
{
	t_vec3	pos;
	double	a;
	double	b;
	double	c;
	double	d;
	
	pos = vec_sub(&ray->origin, origin);
	a = vec_dotproduct(&ray->direction, &ray->direction);
	b = 2.0 * vec_dotproduct(&pos, &ray->direction);
	c = vec_dotproduct(&pos, &pos) - radius * radius;
	d = b * b - 4.0 * a * c;
	if (d < 0.0)
		return (-1.0);
	else
		return ((-b - sqrt(d)) / (2.0 * a));
}
*/

typedef int (*t_matfunc)(t_ray *, t_hitrecord *, t_vec3 *, t_ray *);
t_matfunc mat_funcs[3] = { mat_lambertian, mat_metal, mat_dielectric };

typedef int (*t_hitfunc)(t_ray *, double, t_hitrecord *, t_object *object);
t_hitfunc hit_funcs[4] = { hit_sphere, hit_cylinder, hit_cone, hit_plane };

int		hit_objlist(t_ray *ray, double dist, t_hitrecord *rec, t_objlist *objlist)
{
	t_hitrecord temp_rec;
	int	hit;

	hit = 0;
	while (objlist)
	{
		if (hit_funcs[objlist->object.type](ray, dist, &temp_rec, &objlist->object))
		{
			hit = 1;
			dist = temp_rec.d;
			*rec = temp_rec;
			rec->material = &objlist->object.material;
		}
		objlist = objlist->next;
	}
	return (hit);
}

t_vec3	get_color(t_ray *ray, t_objlist *objlist, int depth)
{
	t_ray		tmpr;
	t_vec3		tmp1;
	t_vec3		tmp2;
	double		d;
	t_hitrecord	rec;

	if (hit_objlist(ray, DBL_MAX, &rec, objlist))
	{
		if (depth < MAX_DEPTH
			&& mat_funcs[rec.material->type](ray, &rec, &tmp1, &tmpr))
		{
			tmp2 = get_color(&tmpr, objlist, depth + 1);
			tmp2 = vec_mul(&tmp1, &tmp2);
			return (tmp2);
		}
		else
		{
			tmp2 = (t_vec3) { 0.0, 0.0, 0.0 };
			return (tmp2);
		}
	}
	else
	{
		tmp1 = vec_unit(&ray->direction);
		d = 0.5 * (tmp1.y + 1.0);
		tmp1 = (t_vec3) { 1.0, 1.0, 1.0 };
		tmp1 = vec_mul_num(&tmp1, 1.0 - d);
		tmp2 = (t_vec3) { 0.5, 0.7, 1.0 };
		tmp2 = vec_mul_num(&tmp2, d);
		tmp1 = vec_add(&tmp1, &tmp2);
//		tmp1 = (t_vec3) { 0.6, 0.2, 0.2 };
		return (tmp1);
	}
}

void	get_ray_dir(t_ray *ray, double x, double y)
{
	ray->direction.x = RANGE
	(
		(double)x,
		0.0,
		(double)RES_X,
		(double)(-RES_X) / RES_Y,
		(double)RES_X / RES_Y
	);
	ray->direction.y = RANGE
	(
		(double)y,
		0.0,
		(double)RES_Y,
		1.0,
		-1.0
	);
	ray->direction.z = -1.0;
}

// TODO: Change drand48() to custom function

t_rgb	sampled_color(t_ray *ray, t_objlist *objlist, int x, int y)
{
	int		i;
	t_rgb 	result;
	t_vec3	temp_res;
	t_vec3	temp;

	i = 0;
	temp = (t_vec3) { 0.0, 0.0, 0.0 };
	while (i < SAMPLING_AMOUNT)
	{
		get_ray_dir(ray, x + drand48(), y + drand48());
		temp_res = get_color(ray, objlist, 0);
		temp = vec_add(&temp, &temp_res);
		++i;
	}
	temp = vec_div_num(&temp, SAMPLING_AMOUNT);
	temp = (t_vec3) { pow(temp.x, GAMMA), pow(temp.y, GAMMA), pow(temp.z, GAMMA) };
	result = (t_rgb) { temp.x * 255, temp.y * 255, temp.z * 255 };
	return (result);
}

#include "events.h"

void	raytrace(t_prog *prog, t_objlist *objlist)
{
	int			x;
	int			y;
	t_ray		ray;
	t_rgb		color;

	y = 0;
	ray.origin = (t_vec3) { 0.0, 0.0, 0.0 };
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			color = sampled_color(&ray, objlist, x, y);
			put_pixel_rgb(color, x, y, &prog->screen);
			++x;
		}
		update_screen(&prog->screen);
		do_events_running(prog);
		++y;
	}
}
