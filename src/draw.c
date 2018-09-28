/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:41:57 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/27 23:41:59 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "rtv1.h"
#include "draw.h"

void	update_screen(t_screen *screen)
{
	SDL_UpdateTexture(
		screen->texture,
		NULL,
		screen->pixels,
		screen->width * sizeof(int));
	SDL_RenderClear(screen->renderer);
	SDL_RenderCopy(screen->renderer, screen->texture, 0, 0);
	SDL_RenderPresent(screen->renderer);
}

void	put_pixel(int color, int x, int y, t_screen *screen)
{
	screen->pixels[x + y * screen->width] = color;
}

void	put_pixel_rgb(t_rgb rgb, int x, int y, t_screen *screen)
{
	int	color;

	color = rgb.r;
	color = (color << 8) + rgb.g;
	color = (color << 8) + rgb.b;
	put_pixel(color, x, y, screen);
}
