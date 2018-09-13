#include "rtv1.h"
#include "exit.h"
#include "events.h"
#include "raytrace.h"
#include "object_list.h"

#include <stdio.h>

t_objlist	*make_objlist(void)
{
	t_object obj;
	t_objlist *result;

	result = NULL;
	/*
	for (int i = 0; i < 100; ++i)
	{
		double ran = drand48();
		if (ran < 0.5)
			obj.type = CYLINDER;
		else
			obj.type = CONE;
		obj.position = (t_vec3) { drand48() * 12.0 - 6.0, drand48() * 12.0 - 6.0, drand48() * -5.0 - 5.0 };
		obj.scale = (t_vec3) { (drand48() + 1.0) / 2.0, (drand48() + 1.0) / 2.0, (drand48() + 1.0) / 2.0 };
		ran = drand48();
		if (ran < 0.8)
			obj.material.type = LAMBERTIAN;
		else
			obj.material.type = METAL;
		obj.material.albedo = (t_vec3) { drand48(), drand48(), drand48() };
		obj.material.fuzz = drand48() / 10.0;
		objlist_push_back(&result, obj);
	}
	*/
	/*
	obj1.type				= CYLINDER;
	obj1.position			= (t_vec3) {  0.0,  0.0, -3.0 };
	obj1.scale				= (t_vec3) {  0.5,  2.0,  0.5 };
	obj1.material.type		= METAL;
	obj1.material.albedo	= (t_vec3) {  0.8,  0.8,  0.8 };
	obj1.material.fuzz		= 0.01;
	obj1.material.refractiveness = 0.0;
	objlist_push_back(&result, obj1);
	*/
	obj.type				= PLANE;
	obj.position			= (t_vec3) {  0.0, -0.5,  0.0 };
	obj.scale				= (t_vec3) {  0.0,  0.0,  0.0 };
	obj.material.type		= METAL;
	obj.material.albedo		= (t_vec3) {  0.8,  0.8,  0.7 };
	obj.material.fuzz		= 0.1;
	objlist_push_back(&result, obj);
	obj.type				= SPHERE;
	obj.position			= (t_vec3) {  1.0,  0.0, -2.0 };
	obj.scale				= (t_vec3) {  0.5,  0.5,  0.5 };
	obj.material.type		= LAMBERTIAN;
	obj.material.albedo		= (t_vec3) {  0.8,  0.2,  0.2 };
	obj.material.fuzz		= 0.0;
	objlist_push_back(&result, obj);
	obj.type				= CYLINDER;
	obj.position			= (t_vec3) {  0.0,  0.0, -2.0 };
	obj.scale				= (t_vec3) {  0.5,  1.0,  0.5 };
	obj.material.type		= LAMBERTIAN;
	obj.material.albedo		= (t_vec3) {  0.2,  0.8,  0.2 };
	obj.material.fuzz		= 0.0;
	objlist_push_back(&result, obj);
	obj.type				= CONE;
	obj.position			= (t_vec3) { -1.0,  0.5, -2.0 };
	obj.scale				= (t_vec3) {  0.5,  1.0,  0.5 };
	obj.material.type		= METAL;
	obj.material.albedo		= (t_vec3) {  0.2,  0.2,  0.8 };
	obj.material.fuzz		= 0.0;
	objlist_push_back(&result, obj);
	return (result);
}

void	run(t_prog *prog)
{
	t_objlist	*objlist;

	while (prog->running)
	{
		if (prog->expose == 1)
		{
			objlist = make_objlist();
			raytrace(prog, objlist);
			objlist_free(&objlist);
			prog->expose = 0;
		}
		do_events(prog);
		SDL_Delay(30);
	}
	exit_program(prog);
}
