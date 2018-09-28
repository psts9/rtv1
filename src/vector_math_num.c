/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 03:55:53 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 03:55:56 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

double	vec_squaredlength(t_vec3 *v)
{
	return
	(
		v->x * v->x +
		v->y * v->y +
		v->z * v->z);
}

double	vec_length(t_vec3 *v)
{
	return (sqrt(vec_squaredlength(v)));
}

double	vec_dotproduct(t_vec3 *v1, t_vec3 *v2)
{
	return
	(
		v1->x * v2->x +
		v1->y * v2->y +
		v1->z * v2->z);
}
