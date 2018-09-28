/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:58:24 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 01:58:26 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdlib.h>

#include "rtv1.h"
#include "libft.h"
#include "error.h"

void	window_init(t_screen *screen, char *program_name)
{
	screen->window = SDL_CreateWindow(
		program_name,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		screen->width,
		screen->height,
		SDL_WINDOW_SHOWN);
	if (!screen->window)
		error_sdl("Could not initialize window");
}

void	renderer_init(t_screen *screen)
{
	screen->renderer = SDL_CreateRenderer(
		screen->window,
		-1,
		SDL_RENDERER_ACCELERATED);
	if (!screen->renderer)
		error_sdl("Could not initialize renderer");
	SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, 0);
}

void	texture_init(t_screen *screen)
{
	screen->texture = SDL_CreateTexture(
		screen->renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC,
		screen->width,
		screen->height);
	if (!screen->texture)
		error_sdl("Could not initialize texture");
}

void	pixels_init(t_screen *screen)
{
	screen->pixels = (int *)malloc(
		screen->width * screen->height * sizeof(int));
	if (!screen->pixels)
		perror_exit("Could not allocate space");
	ft_bzero(
		screen->pixels,
		screen->width * screen->height * sizeof(int));
}
