#include "../ft_rtv1.h"


uint32_t calc_shadow(t_map *map, t_ray *ray, double t, t_sphere *sphere)
{
  t_vec *intersect;
  t_vec *L;
  t_vec *N;
  double dt;
  uint32_t ret_color;

  //printf("T: %f\n", t);
  intersect = malloc(sizeof(t_vec));
  L = malloc(sizeof(t_vec));
  //  intersect = vector_mult(ray->dir, t);
  vector_plus(intersect, ray->origin, vector_mult(ray->dir, t));
  //  vector_mult(intersect, t);
  vector_minus(L, map->light->pos, intersect);
  N = sphere_normal(intersect, sphere);
  dt = vector_dot(normalize(L), normalize(N));
  //  printf("%f\n", dt);
  //  dt = fabs(dt);
  ret_color = /* add_color(0x0000FF, color_combine(dt)); */ color_combine(dt);
  return (ret_color);
}


int intersection(t_ray *ray, double *t, t_sphere *sphere)
{
  t_intersect *inter;

  inter = malloc(sizeof(t_intersect));
  malloc_inter(inter);
  vector_plus(inter->origin, ray->origin, inter->origin);
  vector_plus(inter->direction, ray->dir, inter->direction);
  //  printf("sphere center (%f %f)\n", sphere->center->x, sphere->center->y);
  vector_minus( inter->oc,  inter->origin,  sphere->center);
  inter->b = 2.0 * vector_dot(inter->oc, inter->direction);
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
 
void trace(t_map *map)
{
  int i;
  int j;
  t_sphere *sphere;
  double t;
  t_ray *ray;

  i = 0;
  t = 20000;
  j = 0;
  ray = init_ray(300, 300, 50);
 
  sphere = malloc(sizeof(t_sphere));
  
  circle(sphere, ray->origin, 100, 0xFF0000);
  // printf("circle center %f\n", sphere->center->z);
  
  //  for each pixel in our grid of pixels. Cast a ray that travels from the camera position to the pixel position and checks at each position along the way if it encounters
  while (i < WINDH)
    {
      j = 0;
      while (j < WINDW)
	{
	  update_ray(ray, (double)i, (double)j, 25);
	  // printf("origen (%f %f %f) direction (%f %f %f)\n", ray->origin->x,ray->origin->y, ray->origin->z, ray->dir->x, ray->dir->y, ray->dir->z);   
	  if (intersection(ray, &t, sphere))
	    map->color[i][j] = calc_shadow(map, ray, t, sphere); /* color pixel */
	  j++;
	}
      i++;
    }
  free(sphere);
}

