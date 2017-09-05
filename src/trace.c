#include "../ft_rtv1.h"

uint32_t color_combine(double dt)
{
  uint32_t color;
  // uint32_t white;

  // printf("(%x %x %x) %f\n", (uint32_t)(0xFF0000 * dt), (uint32_t)(0x00FF00 * dt), (uint32_t)(0x0000FF * dt), dt);

  color = mult_color(dt);
  /* color = 0xFFFFFF - color; */
  return(color);
}


