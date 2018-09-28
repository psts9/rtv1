/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:56:42 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 01:56:45 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "rtv1.h"
#include "init.h"
#include "error.h"
#include "scene.h"
#include "vector.h"

static void	sdl_init(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		error_sdl("Could not initalize SDL");
}

void		init_program(t_prog *prog)
{
	prog->init = 1;
	prog->running = 1;
	prog->expose = 1;
}

void		init_scene(t_scene *scene)
{
	scene->cam.origin = (t_vec3) { 0.0, 0.0, 0.0 };
	scene->cam.direction = (t_vec3) { 0.0, 0.0, 0.0 };
	scene->objlist = NULL;
	scene->lightlist = NULL;
}

void		init(t_prog *prog, char *program_name)
{
	prog->screen.window = NULL;
	prog->screen.renderer = NULL;
	prog->screen.texture = NULL;
	prog->screen.width = DEFAULT_SWIDTH;
	prog->screen.height = DEFAULT_SHEIGHT;
	sdl_init();
	window_init(&prog->screen, program_name);
	renderer_init(&prog->screen);
	texture_init(&prog->screen);
	pixels_init(&prog->screen);
	init_program(prog);
}
