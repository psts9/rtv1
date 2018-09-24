#include "vector.h"
#include "libft.h"

void	matrix_identity(double mat[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mat[i][j] = 1.0;
			else
				mat[i][j] = 0.0;
			++j;
		}
		++i;
	}
}

t_vec3	matrix_mul_vec(double mat[4][4], t_vec3 *v)
{
	t_vec3	result;
	double	a;
	double	b;
	double	c;
	double	w;

	a = v->x * mat[0][0] + v->y * mat[1][0] + v->z * mat[2][0] + mat[3][0];
	b = v->x * mat[0][1] + v->y * mat[1][1] + v->z * mat[2][1] + mat[3][1];
	c = v->x * mat[0][2] + v->y * mat[1][2] + v->z * mat[2][2] + mat[3][2];
	w = v->x * mat[0][3] + v->y * mat[1][3] + v->z * mat[2][3] + mat[3][3];
	result.x = a / w;
	result.y = b / w;
	result.z = c / w;
	return (result);
}

t_vec3	matrix_mul_dir(double mat[4][4], t_vec3 *v)
{
	t_vec3	result;
	double	a;
	double	b;
	double	c;

	a = v->x * mat[0][0] + v->y * mat[1][0] + v->z * mat[2][0];
	b = v->x * mat[0][1] + v->y * mat[1][1] + v->z * mat[2][1];
	c = v->x * mat[0][2] + v->y * mat[1][2] + v->z * mat[2][2];
	result.x = a;
	result.y = b;
	result.z = c;
	return (result);
}

void	matrix_print(double mat[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(mat[i][j]);
			ft_putchar(' ');
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}

//void	matrix_mul_vec()
