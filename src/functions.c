#include "../ft_rtv1.h"

double vector_dot(t_vec *a, t_vec *b)
{
  return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
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

t_vec *vector_mult(t_vec *vec, double scalar)
{
  t_vec *ret_vector;

  ret_vector = malloc(sizeof(t_vec));
  ret_vector->x = vec->x * scalar;  
  ret_vector->y = vec->y * scalar;
  ret_vector->z = vec->z * scalar;
  return (ret_vector);
}

void vector_div(t_vec *vec, double scalar)
{
  vec->x /= scalar;  
  vec->y /= scalar;
  vec->z /= scalar;
}
