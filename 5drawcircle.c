#include "mlx/mlx.h"
#include <stdio.h>

#define RED 0x00FF0000

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

/*
** Use coordinates from both points as parameters
*/

void drawCircle(t_data img, int xc, int yc, int x, int y) 
{
    my_mlx_pixel_put(&img, xc+x, yc+y, RED); 
    my_mlx_pixel_put(&img, xc-x, yc+y, RED); 
    my_mlx_pixel_put(&img, xc+x, yc-y, RED); 
    my_mlx_pixel_put(&img, xc-x, yc-y, RED); 
    my_mlx_pixel_put(&img, xc+y, yc+x, RED); 
    my_mlx_pixel_put(&img, xc-y, yc+x, RED); 
    my_mlx_pixel_put(&img, xc+y, yc-x, RED); 
    my_mlx_pixel_put(&img, xc-y, yc-x, RED); 
} 

void    circlesBres(t_data img,int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    drawCircle(img, xc, yc, x, y);

    while (y >= x)
    {
        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(img, xc, yc, x, y);
    }
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    int xc, yc, r;

    // Get Coordinates
    printf("Enter co-ordinates for circle (xc, yc & r): ");
	scanf("%d%d%d", &xc, &yc, &r);

    // Creating Window and Canvas
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 640, 640, "Soli Deo Gloria!");
    img.img = mlx_new_image(mlx, 640, 640);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    
    // Drawing Process
    circlesBres(img, xc, yc, r);


    // Present Pixels
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

