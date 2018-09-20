#ifndef LINKED_LIST_H
# define LINKED_LIST_H

#include "object.h"

typedef struct			s_objlist
{
	t_object			object;
	struct s_objlist	*next;
}						t_objlist;

void	objlist_push_back(t_objlist **list, t_object object);
void	objlist_free(t_objlist **list);
int		objlist_len(t_objlist *list);

#endif
