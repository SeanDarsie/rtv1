#include "../ft_rtv1.h"

uint32_t color_combine(double dt)
{
  uint32_t color;
  // uint32_t white;

  // printf("(%x %x %x) %f\n", (uint32_t)(0xFF0000 * dt), (uint32_t)(0x00FF00 * dt), (uint32_t)(0x0000FF * dt), dt);

  color = mult_color(dt);
  /* color = 0xFFFFFF - color; */
  return(color);
}

t_vec *cross_product(t_vec *a, t_vec *b)
{
  t_vec *cross;

  cross = malloc(sizeof(t_vec));
  cross->x = (a->y * b->z) - (a->z * b->y);
  cross->y = (a->z * b->x) - (a->x * b->z);
  cross->z = (a->x * b->y) - (a->y * b->x);
  return (cross);
}

void update_vector(t_vec *vec, double x, double y, double z)
{
  vec->x = x;
  vec->y = y;
  vec->z = z;
}

void update_ray(t_ray *ray, double x, double y, double z)
{
  update_vector(ray->dir, 0.0, 0.0, 1.0);
  update_vector(ray->origin, x, y, z);

}

double vector_magnitude(t_vec *vec)
{
  return (sqrt(vector_dot(vec, vec)));
}

void init_matrix(double **matrix)
{
  
}

void delete_matrix(double **matrix)
