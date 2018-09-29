/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_simple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 03:56:57 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 03:57:00 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vec_add(t_vec3 *v1, t_vec3 *v2)
{
	return ((t_vec3)
	{
		v1->x + v2->x,
		v1->y + v2->y,
		v1->z + v2->z
	});
}

t_vec3	vec_sub(t_vec3 *v1, t_vec3 *v2)
{
	return ((t_vec3)
	{
		v1->x - v2->x,
		v1->y - v2->y,
		v1->z - v2->z
	});
}

t_vec3	vec_mul(t_vec3 *v1, t_vec3 *v2)
{
	return ((t_vec3)
	{
		v1->x * v2->x,
		v1->y * v2->y,
		v1->z * v2->z
	});
}
