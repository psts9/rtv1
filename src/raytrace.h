#ifndef RAYTRACE_H
# define RAYTRACE_H

#include "rtv1.h"
#include "vector.h"

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

void raytrace(t_prog *prog);

#endif
