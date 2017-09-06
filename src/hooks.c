#include "../ft_rtv1.h"

int		exit_hook(t_map *map)
{
	mlx_destroy_window(map->mlx, map->wind);
	free(map->addr);
	//free(map->color);
	free(map);
	map = NULL;
	exit(0);
	return (0);
}

int           key_hook(int key, t_map *map)
{
  if (key == 53)
    {
      free(map);
      exit(0);
    }
  printf("KEY: %d\n", key);
  if (key == 126)
    {
      mlx_clear_window(map->mlx, map->wind);
      init_vector(map->light->pos, 0, 0, 50);
      trace(map);
      color_image(map);
    }
  if (key == 124)
    {
      mlx_clear_window(map->mlx, map->wind);
      init_vector(map->light->pos, WINDW, 0, 50);
      trace(map);
      color_image(map);
    }
  if (key == 125)
    {
      mlx_clear_window(map->mlx, map->wind);
      init_vector(map->light->pos, WINDW, WINDH, 50);
      trace(map);
      color_image(map);  
    }
  if (key == 123)
    {
      mlx_clear_window(map->mlx, map->wind);
      init_vector(map->light->pos, 0, WINDH, 50);
      trace(map);
      color_image(map);
    }
  if (key == 24)
    {
      mlx_clear_window(map->mlx, map->wind);
      map->light->pos->z += 10;
      trace(map);
      color_image(map);
    }
  if (key == 27)
    {
      mlx_clear_window(map->mlx, map->wind);
      map->light->pos->z -= 10;
      trace(map);
      color_image(map);
    }
   printf("light pos: (%f %f %f)\n", map->light->pos->x, map->light->pos->y, map->light->pos->z);
  return (FALSE);
}
