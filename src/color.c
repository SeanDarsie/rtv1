#include "../ft_rtv1.h"

uint32_t mult_color(double dt)
{
  uint32_t red;
  uint32_t green;
  uint32_t blue;
  //255 255 255
  //
  red = 0xFF * dt;
  if (red > 0xFF)
    red = 0xFF;
  red <<= 16;
  //  printf("%X\n", red);
  green = 0xFF * dt;
  /* if (green > 0xFF) */
  /*   green = 0xFF; */
  green <<= 8;
  blue = 0xFF * dt;
  if (blue > 0xFF)
    blue = 0xFF;
  return (red + green + blue);
  //  return (0xFFFFFF * dt);
}

void malloc_inter(t_intersect *inter)
{
  inter->origin = malloc(sizeof(t_vec));
  inter->origin->x = 0;
  inter->origin->y = 0;
  inter->origin->z = 0;
  inter->direction = malloc(sizeof(t_vec));
  inter->direction->x = 0;
  inter->direction->y = 0;
  inter->direction->z = 0;
  inter->oc = malloc(sizeof(t_vec));
}


uint32_t add_color(uint32_t a, uint32_t b)
{
  uint32_t red;
  uint32_t green;
  uint32_t blue;
  uint32_t tmp;

  tmp = a;
  red = b >> 16;
  green = b << 16;
  green >>= 24;
  blue = b << 24;
  blue >>= 24;
  red += tmp >> 16;
  if (red > 0xFF)
    red = 0xFF;
  tmp <<= 16;
  tmp >>= 24;
  green += tmp;
  if (green > 0xFF)
    green = 0xFF;
  tmp = a << 24;
  tmp >>= 24;
  blue += tmp;
  if (blue > 0xFF)
    blue = 0xFF;
  red <<= 16;
  green <<= 8;
  //printf("(%#X %#X %#X) b = %#X\n", red, green, blue, b);
   return (red + green + blue);
   // return (a | b); 
}
