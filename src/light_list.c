/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:59:52 by pthorell          #+#    #+#             */
/*   Updated: 2018/09/28 02:00:07 by pthorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "light_list.h"
#include "error.h"

void	lightlist_push_back(t_lightlist **list, t_light light)
{
	t_lightlist *new;
	t_lightlist *last;

	new = (t_lightlist *)malloc(sizeof(t_lightlist));
	if (!new)
		perror_exit("Cannot allocate space for lights");
	new->light = light;
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

void	lightlist_free(t_lightlist **list)
{
	t_lightlist *next;

	while (*list)
	{
		next = (*list)->next;
		free(*list);
		*list = next;
	}
	*list = NULL;
}
