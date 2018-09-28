/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:06:14 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:06:16 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

enum	e_object_type
{
	SPHERE,
	CYLINDER,
	CONE,
	PLANE
};

typedef struct			s_object
{
	enum e_object_type	type;
	t_vec3				position;
	t_vec3				albedo;
	t_vec3				rotation;
	double				radius;
}						t_object;

#endif
