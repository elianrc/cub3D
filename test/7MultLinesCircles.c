#include "mlx/mlx.h"
#include <stdio.h>

#define RED 0x00FF0000
#define YELLOW 0x00FFFF00
#define BLUE 0x0000FFFF

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
            my_mlx_pixel_put(&img, x, y, YELLOW);
            y += 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            my_mlx_pixel_put(&img, x, y, YELLOW);
            p = p + 2 * dy;
        }
        x += 1;
    }
}

void circleBres(t_data img, int xc, int yc, int x, int y) 
{
    my_mlx_pixel_put(&img, xc+x, yc+y, RED); 
    my_mlx_pixel_put(&img, xc-x, yc+y, RED); 
    my_mlx_pixel_put(&img, xc+x, yc-y, RED); 
    my_mlx_pixel_put(&img, xc-x, yc-y, RED); 
    my_mlx_pixel_put(&img, xc+y, yc+x, BLUE); 
    my_mlx_pixel_put(&img, xc-y, yc+x, BLUE); 
    my_mlx_pixel_put(&img, xc+y, yc-x, BLUE); 
    my_mlx_pixel_put(&img, xc-y, yc-x, BLUE); 
} 

void    drawCircle(t_data img,int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    circleBres(img, xc, yc, x, y);

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
        circleBres(img, xc, yc, x, y);
    }
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    int xc, yc, r;

    // Get Coordinates
    printf ("__CIRCLE__\n");
    printf("Enter co-ordinates for circle (xc, yc & r): ");
	scanf("%d%d%d", &xc, &yc, &r);


    // Creating Window and Canvas
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 640, 640, "Soli Deo Gloria!");
    img.img = mlx_new_image(mlx, 640, 640);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    // Drawing Process
    int circles = 0;
    while (circles < 100)
    {
        drawCircle(img, xc, yc, r);
        xc++;
        yc--;
        r--;
        circles++;
    }


    // Present Pixels
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}



    //int x0, x1, y0, y1;

    // int lines = 0;
    // while (lines < 5)
    // {
    //     drawLine (x0, y0, x1, y1, img);
    //     x0 += 10;
    //     y0 += 10;
    //     x1 += 10;
    //     y1 += 10;
    //     lines++;
    // }

    // printf("__LINE__\n");
    // printf("Enter co-ordinates of first point: ");
	// scanf("%d%d", &x0, &y0);
	// printf("Enter co-ordinates of second point: ");
	// scanf("%d%d", &x1, &y1);