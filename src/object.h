#ifndef OBJECT_H
# define OBJECT_H

#include "vector.h"

enum object_type
{
	SPHERE,
	CYLINDER
};

enum material_type
{
	LAMBERTIAN,
	METAL,
	DIELECTRIC
};

typedef struct			s_material
{
	enum material_type	type;
	t_vec3				albedo;
	double				fuzz;
	double				refractiveness;
}						t_material;

typedef struct			s_object
{
	enum object_type	type;
	t_material			material;
	t_vec3				position;
	t_vec3				scale;
	t_vec3				rotation;
}						t_object;

#endif
