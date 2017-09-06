#include "../ft_rtv1.h"

t_vec *normalize(t_vec *src)
{
  double mag;
  t_vec *ret_vec;

  ret_vec = malloc(sizeof(t_vec));
  mag = sqrt(vector_dot(src, src));
  ret_vec->x = src->x / mag;
  ret_vec->x = src->y / mag;
  ret_vec->x = src->z / mag;
  return (ret_vec);
}

void init_vector(t_vec *vec, double x, double y, double z)
{
  vec->x = x;
  vec->y = y;
  vec->z = z;
}

void init_ray(t_ray *ray, double x, double y, double z)
{
  init_vector(ray->dir, 0.0, 0.0, 1.0);
  init_vector(ray->origin, x, y, z);
}

t_vec *sphere_normal(t_vec *intersect, t_sphere *sphere)
{
  t_vec *norm_vector;

  norm_vector = malloc(sizeof(t_vec));
  vector_minus(norm_vector, sphere->center, intersect);
  vector_div(norm_vector, sphere->radius);
  return(norm_vector);
}

void circle(t_sphere *circ, t_vec *center, double rad, uint32_t color)
{
  circ->center = malloc(sizeof(t_vec));
  circ->center->x = center->x;
  circ->center->y = center->y;
  circ->center->z = center->z;
  //printf("sphere center: (%f %f %f)\n", circ->center->x, circ->center->y, circ->center->z);
  circ->radius = rad;
  circ->color = color;
}
