#ifndef CAMERA_H
# define CAMERA_H

# include "raytrace.h"

typedef struct	s_camera
{
	t_vec3		origin;
	t_vec3		start_point;
	t_vec3		vertical;
	t_vec3		horizontal;
}				t_camera;

#endif
