#include "../ft_rtv1.h"

//  void (*scene_init)(struct s_map*, char*);

void scene_init1(t_map *map) 
{
  int i;
  t_vec *vector;

  i = 0;
  vector = malloc(sizeof(t_vec));
  map->num_shapes = 2;
  while (i < map->num_shapes)
    {
      map->spheres[i] = malloc(sizeof(t_sphere));
      i++;
    }
  i = 0;
  init_vector(WINDW / 2, WINDH / 2, 50);
  while (i < map->num_shapes)
    {
      circle(map->spheres[i], vector, 100, 0xFF0000);
      i++;
      init_vector(100, 100, 50);
    }
}

/* void scene_init2(t_map *map)  */
/* { */
  
/* } */
/* void scene_init3(t_map *map)  */
/* { */
  
/* } */
/* void scene_init4(t_map *map)  */
/* { */
  
/* } */
/* void scene_init5(t_map *map)  */
/* { */
  
/* } */
