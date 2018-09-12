#include "rtv1.h"
#include "exit.h"
#include "events.h"
#include "raytrace.h"
#include "object_list.h"

#include <stdio.h>

t_objlist	*make_objlist(void)
{
	t_object obj1, obj2, obj3, obj4;
	t_objlist *result;

	result = NULL;
	obj1.type				= SPHERE;
	obj1.position			= (t_vec3) {  0.0,  0.0, -1.0 };
	obj1.scale				= (t_vec3) {  0.5,  0.5,  0.5 };
	obj1.material.type		= LAMBERTIAN;
	obj1.material.albedo	= (t_vec3) {  0.1,  0.2,  0.5 };
	obj1.material.fuzz		= 0.0;
	obj1.material.refractiveness = 0.0;
	objlist_push_back(&result, obj1);
	obj2.type				= SPHERE;
	obj2.position			= (t_vec3) {  0.0,-100.5,-1.0 };
	obj2.scale				= (t_vec3) {100.0,100.0,100.0};
	obj2.material.type 		= LAMBERTIAN;
	obj2.material.albedo	= (t_vec3) {  0.8,  0.8,  0.0 };
	obj2.material.fuzz		= 0.0;
	obj2.material.refractiveness = 0.0;
	objlist_push_back(&result, obj2);
	obj3.type				= SPHERE;
	obj3.position			= (t_vec3) {  1.0,  0.0, -1.0 };
	obj3.scale				= (t_vec3) {  0.5,  0.5,  0.5 };
	obj3.material.type		= METAL;
	obj3.material.albedo	= (t_vec3) {  0.8,  0.6,  0.2 };
	obj3.material.fuzz		= 0.0;
	obj4.material.refractiveness = 0.0;
	objlist_push_back(&result, obj3);
	obj4.type				= SPHERE;
	obj4.position			= (t_vec3) { -1.0,  0.0, -1.0 };
	obj4.scale				= (t_vec3) {  0.5,  0.5,  0.5 };
	obj4.material.type		= DIELECTRIC;
	obj4.material.albedo	= (t_vec3) {  1.0,  1.0,  1.0 };
	obj4.material.fuzz		= 0.0;
	obj4.material.refractiveness = 1.5;
	objlist_push_back(&result, obj4);
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
