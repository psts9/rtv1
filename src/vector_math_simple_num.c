/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_simple_num.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 03:57:29 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 03:57:31 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vec_mul_num(t_vec3 *v, double n)
{
	return ((t_vec3)
	{
		v->x * n,
		v->y * n,
		v->z * n
	});
}

t_vec3	vec_div_num(t_vec3 *v, double n)
{
	return ((t_vec3)
	{
		v->x / n,
		v->y / n,
		v->z / n
	});
}
