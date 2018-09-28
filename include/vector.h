/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:17:34 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:17:35 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3			vec_add(t_vec3 *v1, t_vec3 *v2);
t_vec3			vec_sub(t_vec3 *v1, t_vec3 *v2);
t_vec3			vec_mul(t_vec3 *v1, t_vec3 *v2);
t_vec3			vec_div(t_vec3 *v1, t_vec3 *v2);
t_vec3			vec_add_num(t_vec3 *v, double n);
t_vec3			vec_sub_num(t_vec3 *v, double n);
t_vec3			vec_mul_num(t_vec3 *v, double n);
t_vec3			vec_div_num(t_vec3 *v, double n);
t_vec3			vec_normalize(t_vec3 *v);
t_vec3			vec_negative(t_vec3 *v);
t_vec3			vec_crossproduct(t_vec3 *v1, t_vec3 *v2);
double			vec_squaredlength(t_vec3 *v);
double			vec_length(t_vec3 *v);
double			vec_dotproduct(t_vec3 *v1, t_vec3 *v2);
t_vec3			vec_rotate(t_vec3 *v, t_vec3 *r);

#endif
