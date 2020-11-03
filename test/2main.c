#include <stdio.h>
#include "mlx/mlx.h"

typedef struct s_data {
    
    void    *img;

    char    *addr;

    int     bits_per_pixel;

    int     line_length;

    int     endian;
}               t_data;

int main(void)
{
    t_data  img;
    void    *mlx;

    mlx = mlx_init();
    img.img = mlx_new_image(mlx, 320, 320);
    
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    return (0);
}
