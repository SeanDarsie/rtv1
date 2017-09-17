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

typedef struct s_augmat
{
  double matrix[3][4];
  double Ax;
  double Ay;
  double Az; 
  double Bx;
  double By;
  double Bz; 
  double Cx;
  double Cy;
  double Cz;
  double x;
  double y;
  double z;
  
} t_augmat;

typedef struct s_vec
{
  // A vector contains components in the x y and z directions for 3d space.
  double x;
  double y;
  double z;			/* Z coordinat may not be needed */

  // The normal vector coordinates are those scaled so that the magnitude is 1
  /* double Nx; */
  /* double Ny; */
  /* double Nz; */

  /* // The magnitude is the length of the vector */
  /* double mag; */
} t_vec;

typedef struct s_ray
{
  // A ray is made up of a starting position and a direction vector;
  t_vec *origin;
  t_vec *dir;
  
}              t_ray;


typedef struct s_plane
{
  t_vec *abc;
  double d;
} t_plane;

/* typedef struct s_cone */
/* { */
  
/* }   t_cone; */

typedef struct s_sphere
{
  t_vec *center;
  double radius;
  uint32_t color;
} t_sphere;
  
typedef struct s_cam
{
  double x;
  double y;
  double z;
  
} t_cam;

typedef struct s_object
{
  double x;
  double y;
  double z;
  double size;
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
  int num_shapes;
  t_sphere **spheres;
  t_light *light;
  void (*scene_init)(struct s_map*);
}              t_map;

typedef struct s_objs
{
  t_vec *center;
  double radius; //size
  double height;
  uint32_t color;
  int (*intersect)(t_vec*, double*, struct s_objs*);
} t_objs;
  
void init_struct(t_map *map);
void init_scene(t_scene *scene, t_map *map);
t_vec *init_vector(double x, double y, double z);
void update_ray(t_ray *ray, double x, double y, double z);
void update_vector(t_vec *vec, double x, double y, double z);
t_ray *init_ray(double x, double y, double z);
int intersection(t_ray *ray, double *t,  t_sphere *sphere);
void circle(t_sphere *circ, t_vec *center, double rad, uint32_t color);
void trace(t_map *map);
int		exit_hook(t_map *map);
int             key_hook(int key, t_map *map);
double vector_dot(t_vec *a, t_vec *b);
double vector_magnitude(t_vec *vec);
void vector_minus(t_vec *oc, t_vec *orig, t_vec *dir);
void vector_plus(t_vec *dest, t_vec * a, t_vec *b);
void vector_div(t_vec *vec, double scalar);
t_vec *vector_mult(t_vec *vec, double scalar);
t_vec *normalize(t_vec *src);
t_vec *cross_product(t_vec *a, t_vec *b);
t_vec *sphere_normal(t_vec *intersect, t_sphere *sphere);
uint32_t calc_shadow(t_map *map, t_ray *ray, double t, t_sphere *sphere);
uint32_t mult_color(double dt);
uint32_t color_combine(double dt);
uint32_t add_color(uint32_t a, uint32_t b);
uint32_t sub_color(uint32_t a, uint32_t b);
void malloc_inter(t_intersect *inter);
void scene_init1(t_map *map);
void color_image(t_map *map);

//intersections
t_plane *plane_eq(t_vec *a, t_vec *b, t_vec *c);
int sphere_intersection(t_ray *ray, double *t,  t_objs *sphere);
int triangle_intersection(t_ray *ray, double *t,  t_objs *plane);
int cone_intersection(t_ray *ray, double *t,  t_objs *cone);
int cylander_intersection(t_ray *ray, double *t,  t_objs *cyl);
/* void intit_vector(int x, int y, int z); */
/* void circle() */
/* void cylander() */
/* void cube() */
/* void plane() */

/* void cast_ray(); */
/* void trace(); */
double  **init_matrix(t_vec *a,t_vec *b,t_vec *c, t_vec *pi);
void delete_matrix(double **matrix);

#endif
