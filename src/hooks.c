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
  return (FALSE);
}
