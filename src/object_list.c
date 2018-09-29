/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 02:13:42 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 02:13:43 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "object_list.h"
#include "error.h"

void	objlist_push_back(t_objlist **list, t_object object)
{
	t_objlist *new;
	t_objlist *last;

	new = (t_objlist *)malloc(sizeof(t_objlist));
	if (!new)
		perror_exit("Cannot allocate space for objects");
	new->object = object;
	new->next = NULL;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	objlist_free(t_objlist **list)
{
	t_objlist *next;

	while (*list)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
	*list = NULL;
}
