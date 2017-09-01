#ifndef FT_RTV1_H
# define FT_RTV1_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# define TRUE 1
# define FALSE 0
# define WINDW  500
# define WINDH  500

typedef struct s_point
{
  int x;
  int y;
  int z;
}              t_point;

typedef struct s_vec
{
  // A vector contains components in the x y and z directions for 3d space.
  float x;
  float y;
  float z;			/* Z coordinat may not be needed */

  // The normal vector coordinates are those scaled so that the magnitude is 1
  /* float Nx; */
  /* float Ny; */
  /* float Nz; */

  /* // The magnitude is the length of the vector */
  /* float mag; */
} t_vec;

typedef struct s_ray
{
  // A ray is made up of a starting position and a direction vector;
  t_vec *origin;
  t_vec *dir;
  
}              t_ray;

typedef struct s_sphere
{
  t_vec *center;
  float radius;
  uint32_t color;
} t_sphere;
  
typedef struct s_cam
{
  float x;
  float y;
  float z;
  
} t_cam;

typedef struct s_object
{
  float x;
  float y;
  float z;
  float size;
  int type;
  
} t_object;

typedef struct s_light
{
  t_vec *pos;
} t_light;

typedef struct s_scene 
{
  t_cam cam;
  t_object **objects;
  t_light  **lights;
  // A scene contains a list of objects (maybe a linked list) objects have space and color.
}  t_scene;

typedef struct s_intersect
{
  double b;
  double c;
  double t0;
  double t1;
  double disc;
  t_vec *origin;
  t_vec *direction;
  t_vec *oc;
  
} t_intersect;

typedef struct s_map
{
  void *mlx;
  void *wind;
  void *img;
  uint32_t *addr;
  uint32_t color[WINDH][WINDW];
  int size_l;
  int bpp;
  int endian;
  int windH;
  int windW;
  t_light *light;
  uint32_t **scene;
}              t_map;

void init_struct(t_map *map);
void init_scene(t_scene *scene, t_map *map);
void init_vector(t_vec *vec, float x, float y, float z);
void init_ray(t_ray *ray, float x, float y, float z);
int intersection(t_ray *ray, float *t,  t_sphere *sphere);
void circle(t_sphere *circ, t_vec *center, float rad, uint32_t color);
void trace(t_map *map);
int		exit_hook(t_map *map);
int             key_hook(int key, t_map *map);
double vector_dot(t_vec *a, t_vec *b);
void vector_minus(t_vec *oc, t_vec *orig, t_vec *dir);
void vector_plus(t_vec *dest, t_vec * a, t_vec *b);
void vector_div(t_vec *vec, float scalar);
void vector_mult(t_vec *vec, float scalar);
t_vec *normalize(t_vec *src);
t_vec *sphere_normal(t_vec *intersect, t_sphere *sphere);
/* void intit_vector(int x, int y, int z); */
/* void circle() */
/* void cylander() */
/* void cube() */
/* void plane() */

/* void cast_ray(); */
/* void trace(); */

#endif
