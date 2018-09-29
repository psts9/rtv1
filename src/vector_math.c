/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 03:55:07 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 03:55:22 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "libft.h"
#include "raytrace.h"

t_vec3	vec_normalize(t_vec3 *v)
{
	t_vec3	result;
	double	length;

	length = vec_length(v);
	result = vec_div_num(v, length);
	return (result);
}

t_vec3	vec_negative(t_vec3 *v)
{
	return ((t_vec3)
	{
		-(v->x),
		-(v->y),
		-(v->z)
	});
}
