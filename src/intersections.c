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

t_vec *plane_intersect(t_vec *pix, t_plane *eq)
{
  t_vec *point_of_intersection;
  double t;

  t = ((pix->x * eq->abc->x)
       + (pix->y * eq->abc->y)
       + (pix->z * eq->abc->z));
  t = eq->d / t;
  point_of_intersection = init_vector(pix->x * t,
				      pix->y * t,
				      pix->z * t);
  return (point_of_intersection);
}


t_plane *plane_eq(t_vec *a, t_vec *b, t_vec *c)
{
  t_plane *eq;
  t_vec *ab;
  t_vec *ac;
  t_vec *cross;
  double ret_val;

  ret_val = 0;
  eq = malloc(sizeof(t_plane));
  ab = malloc(sizeof(t_vec));
  ac = malloc(sizeof(t_vec));
  vector_minus(ab, b, a);
  vector_minus(ac, c, a);
  cross = cross_product(ac, ac);
  ret_val += cross->x * a->x;
  ret_val += cross->y * a->y;
  ret_val += cross->z * a->z;
  eq->abc = init_vector(cross->x, cross->y, cross->z);
  ret_val *= -1;
  eq->d = ret_val;
  return (eq);
}
//pi is the point of intersection


/* int inside_triangle(t_vec *a,t_vec *b,t_vec *c, t_vec *pi)  */
/* { */
/*   double **matrix; */
/*   int i; */
/*   int j; */

/*   i = -1; */
/*   matrix = init_matrix(a, b, c, pi); */



/* } */
/* /\* a[t*px] b[tPy] + c[tpz] + d = 0 *\/ */
