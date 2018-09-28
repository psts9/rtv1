/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:11:32 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:11:50 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <SDL2/SDL.h>

# define DEFAULT_SWIDTH		1920
# define DEFAULT_SHEIGHT	1080

# define EPSILON 0.000001
# define DEG_TO_RAD 0.01745329251994
# define RAD_TO_DEG 57.2957795130823

# define VIEWING_DIST 500.0
# define GAMMA 1.0
# define DS_SHADE 0.0

typedef struct		s_screen
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	int				width;
	int				height;
	int				*pixels;
}					t_screen;

typedef struct		s_prog
{
	char			*name;
	int				running;
	int				expose;
	int				init;
	t_screen		screen;
	SDL_Event		event;
}					t_prog;

typedef struct s_scene	t_scene;

#endif
