#include "mlx/mlx.h"
#include <stdio.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main (void) 
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    // initialize
    mlx = mlx_init();
    
    // create window
    mlx_win = mlx_new_window(mlx, 320, 640, "Soli Deo GLoria");
    
    // create image
    img.img = mlx_new_image(mlx, 320, 640);

    // bring image address (canvas)
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    // putting pixels in tmp image
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

    // present modified image
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    // loop for window
    mlx_loop(mlx);
}
