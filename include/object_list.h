/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:08:58 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 04:09:10 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_LIST_H
# define OBJECT_LIST_H

# include "object.h"

typedef struct			s_objlist
{
	t_object			object;
	struct s_objlist	*next;
}						t_objlist;

void					objlist_push_back(t_objlist **list, t_object object);
void					objlist_free(t_objlist **list);
int						objlist_len(t_objlist *list);

#endif
