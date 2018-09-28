/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:12:14 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 02:12:30 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "object_list.h"
#include "events.h"
#include "exit.h"
#include "raytrace.h"
#include "scene.h"

#include "libft.h"
#include "object_list.h"
#include "light_list.h"
#include <unistd.h>

void	run(t_prog *prog, char *file_name)
{
	t_scene	scene;

	while (prog->running)
	{
		if (prog->expose)
		{
			if (file_to_scene(file_name, &scene))
			{
				raytrace(prog, &scene);
				objlist_free(&scene.objlist);
				lightlist_free(&scene.lightlist);
			}
			else
			{
				ft_putendl("File is invalid!");
				if (prog->init)
					exit(-1);
			}
			prog->expose = 0;
			prog->init = 0;
		}
		do_events(prog);
		SDL_Delay(30);
	}
	exit_program(prog);
}
