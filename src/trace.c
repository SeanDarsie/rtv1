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

double  **init_matrix(t_vec *a,t_vec *b,t_vec *c, t_vec *pi)
{
  double **matrix;
  int i;
  
  matrix = (double**)malloc(sizeof(double*) * 3);
  i = -1;
  while (++i < 3)
    matrix[i] = (double*)malloc(sizeof(double) * 4);
  matrix[0][0] = a->x;
  matrix[0][1] = b->x;
  matrix[0][2] = c->x;
  matrix[0][3] = pi->x;
  matrix[1][0] = a->y;
  matrix[1][1] = b->y;
  matrix[1][2] = c->y;
  matrix[1][3] = pi->y;
  matrix[2][0] = a->z;
  matrix[2][1] = b->z;
  matrix[2][2] = c->z;
  matrix[2][3] = pi->z;
  return (matrix);
}

void delete_matrix(double **matrix)
{
  /*  matrix = (double**)malloc(sizeof(double*) * 3);
  i = -1;
  while (++i < 3)
    matrix[i] = (double*)malloc(sizeof(double) * 4); */
  int i;

  i = -1;
  while (++i < 3)
    free(matrix[i]);
  free(matrix);
}
