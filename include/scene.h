/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:12:05 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:12:07 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "object_list.h"
# include "light_list.h"
# include "camera.h"

typedef struct	s_scene
{
	t_objlist	*objlist;
	t_lightlist *lightlist;
	t_camera	cam;
}				t_scene;

enum	e_scene_object
{
	SCENE_CAMERA,
	SCENE_OBJECT,
	SCENE_LIGHT
};

int				file_to_scene(char *filename, t_scene *scene);

#endif
