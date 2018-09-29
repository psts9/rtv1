/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:04:51 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:05:03 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_LIST_H
# define LIGHT_LIST_H

# include "light.h"

typedef struct			s_lightlist
{
	t_light				light;
	struct s_lightlist	*next;
}						t_lightlist;

void					lightlist_push_back(t_lightlist **list, t_light light);
void					lightlist_free(t_lightlist **list);

#endif
