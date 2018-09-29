/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:43:19 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/27 23:43:20 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void	do_events(t_prog *prog)
{
	while (SDL_PollEvent(&prog->event))
	{
		if (prog->event.type == SDL_KEYDOWN)
		{
			if (prog->event.key.keysym.sym == SDLK_SPACE)
				prog->expose = 1;
			if (prog->event.key.keysym.sym == SDLK_ESCAPE)
				prog->running = 0;
		}
		if (prog->event.type == SDL_QUIT)
			prog->running = 0;
	}
}

void	do_events_running(t_prog *prog)
{
	while (SDL_PollEvent(&prog->event))
	{
		if (prog->event.type == SDL_KEYDOWN)
		{
			if (prog->event.key.keysym.sym == SDLK_ESCAPE)
				exit(EXIT_SUCCESS);
		}
		if (prog->event.type == SDL_QUIT)
			exit(EXIT_SUCCESS);
	}
}
