#include "../ft_rtv1.h"


int intersection(t_ray *ray, float *t, t_sphere *sphere)
{
  t_intersect *inter;

  inter = malloc(sizeof(t_intersect));
  inter->origin = malloc(sizeof(t_vec));
  inter->direction = malloc(sizeof(t_vec));
  inter->oc = malloc(sizeof(t_vec));
  
  inter->origin = ray->origin;
  inter->direction = ray->dir;
  //  printf("sphere center (%f %f)\n", sphere->center->x, sphere->center->y);
  vector_minus( inter->oc,  inter->origin,  sphere->center);
  inter->b = 2 * vector_dot(inter->oc, inter->direction);
  inter->c = vector_dot(inter->oc, inter->oc);
  inter->c -= (sphere->radius * sphere->radius);
  inter->disc = (inter->b * inter->b) - (4 * inter->c);
  if (inter->disc < 0)
    return (FALSE);
  else
    {
      inter->disc = sqrt(inter->disc);
      inter->t0 = -inter->b - inter->disc;
      inter->t1 = -inter->b + inter->disc;
      *t = (inter->t0 < inter->t1) ? inter->t0 : inter->t1;
      free(inter);
      return (TRUE);
    }
  free(inter);
  return(TRUE);
}
 

void circle(t_sphere *circ, t_vec *center, float rad, uint32_t color)
{
  circ->center = malloc(sizeof(t_vec));
  circ->center->x = center->x;
  circ->center->y = center->y;
  circ->center->z = center->z;
  printf("sphere center (%f %f %f)\n", circ->center->x, circ->center->y, circ->center->z);
  circ->radius = rad;
  circ->color = color;
}
