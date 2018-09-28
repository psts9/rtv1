/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:01:43 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:02:15 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector.h"

enum	e_light_type
{
	DIRECTIONAL,
	POINT
};

typedef struct			s_light
{
	enum e_light_type	type;
	double				intensity;
	t_vec3				albedo;
	t_vec3				position;
	t_vec3				rotation;
}						t_light;

#endif
