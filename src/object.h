#ifndef OBJECT_H
# define OBJECT_H

#include "vector.h"

enum object_type
{
	CIRCLE
};

typedef struct			s_object
{
	enum object_type	object;
	t_vec3				position;
	t_vec3				scale;
};

#endif
