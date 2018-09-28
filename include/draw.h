/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 03:59:39 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 03:59:40 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "rtv1.h"
# include "color.h"

void	put_pixel(int color, int x, int y, t_screen *screen);
void	put_pixel_rgb(t_rgb rgb, int x, int y, t_screen *screen);
void	update_screen(t_screen *screen);

#endif
