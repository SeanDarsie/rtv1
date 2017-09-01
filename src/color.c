#include "../ft_rtv1.h"

uint32_t mult_color(double dt)
{
  uint32_t red;
  uint32_t green;
  uint32_t blue;
  //255 255 255
  //
  red = 0xFF * dt;
 /*  if (red > 0xFF) */
 /* red = 0x0; */
  red <<= 16;
  green = 0xFF * dt;
  /* if (green > 0xFF) */
  /*   green = 0x0; */
  green <<= 8;
  blue = 0xFF * dt;
  return (red + green + blue);
}

void malloc_inter(t_intersect *inter)
{
 
  inter->origin = malloc(sizeof(t_vec));
  inter->direction = malloc(sizeof(t_vec));
  inter->oc = malloc(sizeof(t_vec));
}
