/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:42:15 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/27 23:42:36 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdio.h>

#include "libft.h"

void	error_sdl(char *str)
{
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl(SDL_GetError());
	exit(EXIT_FAILURE);
}

void	perror_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
