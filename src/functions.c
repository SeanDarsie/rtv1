#include "../ft_rtv1.h"

double vector_dot(t_vec *a, t_vec *b)
{
  return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void vector_plus(t_vec *dest, t_vec * a, t_vec *b)
{
  dest->x = a->x + b->x;
  dest->y = a->y + b->y;
  dest->z = a->z + b->z;
}

void vector_minus(t_vec *dest, t_vec *orig, t_vec *dir)
{
  dest->x = orig->x - dir->x;
  dest->y = orig->y - dir->y;
  dest->z = orig->z - dir->z;
}

void vector_mult(t_vec *vec, float scalar)
{
  vec->x *= scalar;  
  vec->y *= scalar;
  vec->z *= scalar;
}

void vector_div(t_vec *vec, float scalar)
{
  vec->x /= scalar;  
  vec->y /= scalar;
  vec->z /= scalar;
}
