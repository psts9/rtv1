/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:43:31 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/27 23:43:33 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void	exit_program(t_prog *prog)
{
	SDL_DestroyTexture(prog->screen.texture);
	SDL_DestroyRenderer(prog->screen.renderer);
	SDL_DestroyWindow(prog->screen.window);
	SDL_Quit();
}
