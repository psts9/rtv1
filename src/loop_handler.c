#include "rtv1.h"
#include "object_list.h"
#include "events.h"
#include "exit.h"
#include "raytrace.h"

t_objlist	*make_objlist(char *scene_file)
{
	t_object	obj;
	t_objlist	*result;

	result = NULL;
	/*
	obj.type = CONE;
	obj.position = (t_vec3) { 0.0, 0.0, -100.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.5;
	objlist_push_back(&result, obj);
	*/
	obj.type = CYLINDER;
	obj.position = (t_vec3) { -2.0, 0.0, -5.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.2;
	objlist_push_back(&result, obj);
	obj.type = CYLINDER;
	obj.position = (t_vec3) { 2.0, 0.0, -5.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.05;
	objlist_push_back(&result, obj);
	obj.type = CONE;
	obj.position = (t_vec3) { 3.0, 0.0, -5.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.5;
	objlist_push_back(&result, obj);
	obj.type = CONE;
	obj.position = (t_vec3) { -3.0, 0.0, -5.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.5;
	objlist_push_back(&result, obj);
	obj.type = SPHERE;
	obj.position = (t_vec3) { 1.0, 0.0, -5.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.2;
	objlist_push_back(&result, obj);
	obj.type = SPHERE;
	obj.position = (t_vec3) { -1.0, 0.0, -5.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.5;
	objlist_push_back(&result, obj);
	obj.type = SPHERE;
	obj.position = (t_vec3) { 0.0, 0.0, -5.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.1;
	objlist_push_back(&result, obj);
	obj.type = PLANE;
	obj.position = (t_vec3) { 0.0, -2.0, 0.0 };
	obj.albedo = (t_vec3) { drand48(), drand48(), drand48() };
	obj.radius = 0.5;
	objlist_push_back(&result, obj);

	scene_file = NULL;
	return (result);
}

#include "libft.h"

void run(t_prog *prog, char *scene_file)
{
	t_objlist	*objlist;

	while (prog->running)
	{
		if (prog->expose)
		{
			objlist = make_objlist(scene_file);
			raytrace(prog, objlist);
			objlist_free(&objlist);
			prog->expose = 0;
		}
		do_events(prog);
		SDL_Delay(30);
	}
	exit_program(prog);
}
