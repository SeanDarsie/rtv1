#include "../ft_rtv1.h"

int sphere_intersection(t_ray *ray, double *t, t_objs *sphere)
{
  t_intersect *inter;

  inter = malloc(sizeof(t_intersect));
  malloc_inter(inter);
  vector_plus(inter->origin, ray->origin, inter->origin);
  vector_plus(inter->direction, ray->dir, inter->direction);
  //  printf("sphere center (%f %f)\n", sphere->center->x, sphere->center->y);
  vector_minus( inter->oc,  inter->origin,  sphere->center);
  inter->b = 2 * vector_dot(inter->oc, inter->direction);
  inter->c = vector_dot(inter->oc, inter->oc);
  inter->c -= (sphere->radius * sphere->radius);
  inter->disc = (inter->b * inter->b) - (4 * inter->c);
  if (inter->disc < 0)
    {
      free(inter);
      return (FALSE);
    }
  else
    {
      inter->disc = sqrt(inter->disc);
      inter->t0 = -inter->b - inter->disc;
      inter->t1 = -inter->b + inter->disc;
      *t = (inter->t0 < inter->t1) ? inter->t0 : inter->t1;
      free(inter);
      return (TRUE);
    }
  return(TRUE);
}

/* int triangle_intersection(t_ray *ray, double *t, t_objs *plane) */
/* { */
/* } */

/* int cone_intersection(t_ray *ray, double *t, t_objs *cone) */
/* { */
/* } */

/* int cylander_intersection(t_ray *ray, double *t, t_objs *cylander) */
/* { */
/* } */

/* void plane(t_vec *pixel, t_vec *a, t_vec *b, t_vec *c) */
/* { */
/*   double matrix[3][4]; */

  
/* } */

/* a[(1 - t)*cx + t*px] b[(1 - t)cy + tPy] + c[(1 - t)Cz + tpz] + d = 0 */
