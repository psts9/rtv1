/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:01:14 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:01:25 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "rtv1.h"

void	init(t_prog *prog, char *program_name);
void	window_init(t_screen *screen, char *program_name);
void	renderer_init(t_screen *screen);
void	texture_init(t_screen *screen);
void	pixels_init(t_screen *screen);
void	init_scene(t_scene *scene);

#endif
