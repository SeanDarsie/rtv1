#include "../ft_rtv1.h"

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

t_square *create_square(t_vec *a, t_vec *b, t_vec *c, t_vec *d)
{
}
