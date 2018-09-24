#ifndef MATRIX_H
# define MATRIX_H

# include "vector.h"

void	matrix_identity(double mat[4][4]);
void	matrix_print(double mat[4][4]);
t_vec3	matrix_mul_vec(double mat[4][4], t_vec3 *v);
t_vec3	matrix_mul_dir(double mat[4][4], t_vec3 *v);

#endif
