#include "../ft_rtv1.h"

uint32_t color_combine(double dt)
{
  uint32_t color = 0xFFFFFF;
  // uint32_t white;

  printf("(%x %x %x) %f\n", (uint32_t)(0xFF0000 * dt), (uint32_t)(0x00FF00 * dt), (uint32_t)(0x0000FF * dt), dt);

  color = (0xFF0000 + color *dt);
  return(color);
}

uint32_t calc_shadow(t_map *map, t_ray *ray, float t, t_sphere *sphere)
{
  t_vec *intersect;
  t_vec *L;
  t_vec *N;
  double dt;
  uint32_t ret_color;
  
  intersect = malloc(sizeof(t_vec));
  L = malloc(sizeof(t_vec));
  vector_mult(ray->dir, t);
  vector_plus(intersect, ray->origin, ray->dir);
  //  vector_mult(intersect, t);
  vector_minus(L, map->light->pos, intersect);
  N = sphere_normal(intersect, sphere);
  dt = vector_dot(normalize(L), normalize(N));
  //  printf("%f\n", dt);
  dt = fabs(dt);
  ret_color = color_combine(dt);
  //  printf("%x\n", ret_color);
  /* if (ret_color > 0xFF0000) */
  /*   ret_color = 0xFF0000; */
  return (ret_color);
}

void trace(t_map *map)
{
  int i;
  int j;
  t_sphere *sphere;
  float t;
  t_ray *ray;

  i = 0;
  j = 0;
  ray = malloc(sizeof(t_ray));
  ray->origin = malloc(sizeof(t_vec));
  ray->dir = malloc(sizeof(t_vec));
  sphere = malloc(sizeof(t_sphere));
  init_ray(ray, map->windW / 2, map->windH / 2, 50);
  
  circle(sphere, ray->origin, 75, 0xFF0000);
  // printf("circle center %f\n", sphere->center->z);
  
  //  for each pixel in our grid of pixels. Cast a ray that travels from the camera position to the pixel position and checks at each position along the way if it encounters
  while (i < WINDH)
    {
      j = 0;
      while (j < WINDW)
	{
	  init_ray(ray, (float)i, (float)j, 0);
	  // printf("origen (%f %f %f) direction (%f %f %f)\n", ray->origin->x,ray->origin->y, ray->origin->z, ray->dir->x, ray->dir->y, ray->dir->z);   
	  t = 20000;
	  if (intersection(ray, &t, sphere))
	    map->color[i][j] = calc_shadow(map, ray, t, sphere); /* color pixel */
	  j++;
	}
      i++;
    }
  free(sphere);
}
