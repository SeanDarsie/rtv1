
#include "../ft_rtv1.h"



/* void init_scene(t_scene *scene, t_map *map) */
/* { */
/*   scene->cam.x = 0.0; */
/*   scene->cam.y = 0.0; */
/*   scene->cam.z = 0.0; */
/* } */
void test(void)
{
  t_vec *a;
  t_vec *b;
  t_vec *c;
  t_vec *pi;
  double **matrix;
  int flag;
  double *sol;

  a = init_vector(1, 2, 2);
  b = init_vector(3, 3, 3);
  c = init_vector(4, 5, 4);
  pi = init_vector(1.9, 2.3, 2.4);
  matrix = init_matrix(a,b,c,pi);
  print_mat(matrix);
  printf("\n");
  flag = forward_elim(matrix);
  //  if (flag == -1)
  sol = back_sub(matrix);
  if (sol[0] > 0 && sol[1] > 0 && sol[2] > 0)
    printf("ray DOES intersect triangle");
  else if (sol[0] < 0 && sol[1] < 0 && sol[2] < 0)
    printf("ray DOES intersect triangle");
  else
    printf("ray does NOT intersect triangle");
  print_mat(matrix);
  delete_matrix(matrix);
  /* printf("\nSolution for the system:\n"); */
  /* for (int i=0; i<3; i++) */
  /*   printf("%lf\n", sol[i]); */
  
  free(sol);
  free(a);
  free(b);
  free(c);
  free(pi);
}

void init_structs(t_map *map)
{
  map->windH = 500;
  map->windW = 500;
  map->mlx = mlx_init();
  map->wind = mlx_new_window(map->mlx, WINDW, WINDH, "rtv1");
  map->img = mlx_new_image(map->mlx, WINDW, WINDH);
  map->addr = (unsigned int*)mlx_get_data_addr(map->img, &map->bpp,
					       &map->size_l, &map->endian);
  ft_bzero(map->addr, (WINDW * WINDH) * 4);
  ft_bzero(map->color, (WINDH * WINDW) * 4);
  map->light = malloc(sizeof(t_sphere));
  map->light->pos = malloc(sizeof(t_vec));
  map->light->pos = init_vector(WINDW, 0 , 50);
  // printf("light pos: (%f %f %f)\n", map->light->pos->x, map->light->pos->y, map->light->pos->z);
  map->scene_init = scene_init1;
  // test();
}

void  object(t_object *obj, double x, double y, double z)
{
  
  obj->x = x;
  obj->y = y;
  obj->z = z;

}

void color_image(t_map *map)
{
  int i;
  int j;
  int k;

  i = 0;
  k = 0;
  while (i < WINDH)
    {
      j = 0;
      while (j < WINDW)
	{
	  map->addr[k] = map->color[i][j];
	  j++;
	  k++;
	}
      //k++;
      i++;
    }
  mlx_put_image_to_window(map->mlx,map->wind, map->img, 0, 0);
}

int main(int ac, char **av)
{
  t_map *map;
  //  t_scene *scene;

  //scene = (t_scene*)malloc(sizeof(t_scene));
  map = (t_map*)malloc(sizeof(t_map));
  init_structs(map);
  // init_scene(scene, map);
  trace(map);
  color_image(map);
  (void)av;
  ac  = 0;
  mlx_hook(map->wind, 17, 0, exit_hook, map);
  mlx_hook(map->wind, 2, 3, key_hook, map);
  mlx_loop(map->mlx);
  return (0);
}
