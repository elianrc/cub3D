/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveResize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:58:19 by erc               #+#    #+#             */
/*   Updated: 2020/11/05 11:51:18 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
**------------ STRUCTURES -------------
*/

typedef struct  s_data {
    void        *mlx;
    void        *window;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         posX;
    int         posY;
    int         radius;
}               t_data;

/*
**  ------------ FUNCTIONS ------------
*/

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void circleBres(t_data *img, int xc, int yc, int x, int y) 
{
    my_mlx_pixel_put(img, xc+x, yc+y, RED); 
    my_mlx_pixel_put(img, xc-x, yc+y, RED); 
    my_mlx_pixel_put(img, xc+x, yc-y, RED); 
    my_mlx_pixel_put(img, xc-x, yc-y, RED); 
    my_mlx_pixel_put(img, xc+y, yc+x, BLUE); 
    my_mlx_pixel_put(img, xc-y, yc+x, BLUE); 
    my_mlx_pixel_put(img, xc+y, yc-x, BLUE); 
    my_mlx_pixel_put(img, xc-y, yc-x, BLUE); 
} 

void    drawCircle(t_data *img,int xc, int yc, int r)
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

int             move(int keycode, t_data *img)
{
    if (keycode == ESC)
    {
        printf("-- CLOSING --\n");
        exit(1);
    }
    else if (keycode == W)
    {
        printf("W\n");
        img->posY -= 10;
    }
    else if (keycode == A)
    {
        printf("A\n");
        img->posX -= 10;
    }
    else if (keycode == S)
    {
        printf("S\n");
        img->posY += 10;
    }
    else if (keycode == D)
    {
        printf("D\n");
        img->posX += 10;
    }
    else if (keycode == E)
    {
        printf("E\n");
        img->radius -= 10;
    }
    else if (keycode == R)
    {
        printf("R\n");
        img->radius += 10;
    }
    else
        printf("%d\n", keycode);
    return (0);
}

int             close_window(int keycode, t_data *img)
{
    printf("-- CLOSING --\n");
    exit(1);
    return (0);
}

int         renderer(t_data *img)
{   
    mlx_destroy_image(img->mlx, img->img);
    img->img = mlx_new_image(img->mlx, 640, 640);
    drawCircle(img, img->posX, img->posY, img->radius);
    mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}

/*
** --------------- MAIN -----------------
*/

int             main(void)
{
    t_data  img;
    img.posX = 320;
    img.posY = 320;
    img.radius = 100;

    // Creating Window and Canvas
    img.mlx = mlx_init();
    img.window = mlx_new_window(img.mlx, 640, 480, "SOLI DEO GLORIA!");
    img.img = mlx_new_image(img.mlx, 640, 640);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    // Setting Hooks
    mlx_key_hook(img.window, move, &img);
    mlx_hook(img.window, 17, 1L<<2, close_window, &img);
    mlx_loop_hook(img.mlx, renderer, &img);
    mlx_loop(img.mlx);
} 