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
/*   double t; */
/*   double matrix[3][4] = {{a->x, a->y, a->z, t}, */
/* 	    {b->x, b->y, b->z, t}, */
/* 	    {c->x, c->y, c->z, t}};  ; */
  
/*   t = plane_eq(a, b, c); */
/*   /\* matrix = {{a->x, a->y, a->z, t}, *\/ */
/*   /\* 	    {b->x, b->y, b->z, t}, *\/ */
/*   /\* 	    {c->x, c->y, c->z, t}};  *\/  */
/* } */





//pi is the point of intersection


int inside_triangle(t_vec *a,t_vec *b,t_vec *c, t_vec *pi)
{
  double **matrix;
  double *solution;
  int flag;

  matrix = init_matrix(a, b, c, pi);
  flag = forward_elim(matrix);
  solution = back_sub(matrix);
  if (solution[0] > 0 && solution[1] > 0 && solution[2] > 0)
    {
      printf("ray DOES intersect triangle");
      delete_matrix(matrix);
      free(solution);
      return (TRUE);
    }
  else if (solution[0] < 0 && solution[1] < 0 && solution[2] < 0)
    {
      printf("ray DOES intersect triangle");
      delete_matrix(matrix);
      free(solution);
      return (TRUE);
    }
  else
    {
      printf("ray does NOT intersect triangle");
      delete_matrix(matrix);
      free(solution);
      return (FALSE);
    }
  return (0);
}

/* } */
/* /\* a[t*px] b[tPy] + c[tpz] + d = 0 *\/ */
