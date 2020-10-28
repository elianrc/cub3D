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

/*
** Use coordinates from both points as parameters
*/

void drawLine(int x0, int y0, int x1, int y1, t_data img)
{
    int dx, dy, p, x, y;

    dx = x1 - x0;
    dy = y1 - y0;

    x = x0;
    y = y0;

    p = 2 * dy - dx;

    while (x < x1)
    {
        if (p >= 0)
        {
            my_mlx_pixel_put(&img, x, y, 0x00FF0000);
            y += 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            my_mlx_pixel_put(&img, x, y, 0x00FF0000);
            p = p + 2 * dy;
        }
        x += 1;
    }
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    int x0, x1, y0, y1;

    // Get Coordinates
    printf("Enter co-ordinates of first point: ");
	scanf("%d%d", &x0, &y0);

	printf("Enter co-ordinates of second point: ");
	scanf("%d%d", &x1, &y1);

    // Creating Window and Canvas
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 640, 640, "Soli Deo Gloria!");
    img.img = mlx_new_image(mlx, 640, 640);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    
    // Drawing Process
    drawLine (x0, y0, x1, y1, img);


    // Present Pixels
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
