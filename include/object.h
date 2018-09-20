#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

enum object_type
{
	SPHERE,
	CYLINDER,
	CONE,
	PLANE
};

typedef struct			s_object
{
	enum object_type	type;
	t_vec3				position;
	t_vec3				albedo;
	t_vec3				rotation;
	double				radius;
}						t_object;

#endif
