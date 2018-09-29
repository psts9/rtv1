/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:55:47 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 01:55:49 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parsing.h"
#include "object_list.h"

static t_light	get_default_light(enum e_light_type	type)
{
	t_light light;

	light.type = type;
	light.albedo = (t_vec3) { 1.0, 1.0, 1.0 };
	light.position = (t_vec3) { 0.0, 0.0, 0.0 };
	light.rotation = (t_vec3) { 0.0, 0.0, 0.0 };
	light.intensity = 1.0;
	return (light);
}

static t_object	get_default_object(enum e_object_type type)
{
	t_object obj;

	obj.type = type;
	obj.albedo = (t_vec3) { 1.0, 1.0, 1.0 };
	obj.position = (t_vec3) { 0.0, 0.0, 0.0 };
	obj.rotation = (t_vec3) { 0.0, 0.0, 0.0 };
	obj.radius = 0.5;
	return (obj);
}

static void		get_defaults(t_object *obj, t_light *light, int type)
{
	*obj = get_default_object(type);
	*light = get_default_light(type);
}

static void		do_scene_pushback_if(t_scene *scene, t_object *obj,
			t_light *light, enum e_scene_object scene_object_type)
{
	if (scene_object_type == SCENE_OBJECT)
		objlist_push_back(&scene->objlist, *obj);
	else if (scene_object_type == SCENE_LIGHT)
		lightlist_push_back(&scene->lightlist, *light);
}

int				get_parameters(int fd, t_scene *scene, int type,
				enum e_scene_object scene_object_type)
{
	t_object	obj;
	t_light		light;
	int			ret;
	char		*line;

	get_defaults(&obj, &light, type);
	get_next_line(fd, &line);
	while (line[0] == ' ' || line[0] == '\t')
	{
		if (scene_object_type == SCENE_CAMERA)
			ret = get_camera_args(line, scene);
		else if (scene_object_type == SCENE_OBJECT)
			ret = get_object_args(line, &obj);
		else if (scene_object_type == SCENE_LIGHT)
			ret = get_light_args(line, &light);
		free(line);
		if (!ret)
			return (free_scene_lists(&scene));
		if ((ret = get_next_line(fd, &line)) == 0)
			break ;
	}
	free(line);
	do_scene_pushback_if(scene, &obj, &light, scene_object_type);
	return (1);
}
