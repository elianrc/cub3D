/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:54:40 by erc               #+#    #+#             */
/*   Updated: 2020/11/12 08:48:03 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define tileSize 32
# define mapRows 11
# define mapCols 15
# define WINDOW_WIDTH  mapCols * tileSize
# define WINDOW_HEIGHT  mapRows * tileSize

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

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void            drawLine(int x1, int y1, int x2, int y2, t_data *img, int color)
{
    int i;
    int x;
    int y;
    int dx;
    int dy;
    int step;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
        step = dx;
    else
        step = dy;
    dx /= step;
    dy /= step;
    x = x1;
    y = y1;
    i = 1;
    while (i <= step)
    {
        my_mlx_pixel_put(img, x, y, color);
        x += dx;
        y += dy;
        i++;
    }
}

void            drawSquare(t_data *img, int x, int y, int size, int color)
{
    int i;
    int j;
    int originalPos;
    int originalSize;

    i = 0;
    j = 0;
    originalPos = x;
    while (i < size)
    {
        while (j < size)
        {
            my_mlx_pixel_put(img, x, y, color);
            x++;
            j++;
        }
        y++;
        i++;
        x = originalPos;
        j = 0;
    }
}

void            drawGrid(t_data *img, int color)
{
    int i;
    int j;
    
    i = 0;
    j = 0;    
    while ( i < mapRows)
    {
        drawLine(0 , i * tileSize, WINDOW_WIDTH, i * tileSize, img, color);
        i++;
    }
    while ( j < mapCols)
    {
        drawLine( j * tileSize, 0,  j * tileSize, WINDOW_HEIGHT, img, color);
        j++;
    }
}

void            drawMap(t_data *img, int color)
{
    int i;
    int tileX;
    int tileY;
    int j;

    i = 0;
    while (i < mapRows)
    {
        j = 0;
        while (j < mapCols)
        {
            tileX = j * tileSize;
            tileY = i * tileSize;
            drawSquare(img, tileX, tileY, tileSize, color);
            j++;
        }
        i++;
    }
}

void            drawPlayer(t_data *img, int posX, int posY, int size, int color)
{
    int i;
    int j;
    int originalPos;
    int originalSize;

    i = 0;
    j = 0;
    originalPos = posX;
    while (i < size)
    {
        while (j < size)
        {
            my_mlx_pixel_put(img, posX, posY, color);
            posX++;
            j++;
        }
        posY++;
        i++;
        posX = originalPos;
        j = 0;
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
    img->img = mlx_new_image(img->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Draw Process
    drawMap(img, WHITE);
    drawGrid(img, BLACK);
    drawPlayer(img, img->posX, img->posY, tileSize / 2, RED);

    mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
    return (0);
}

int main(void)
{
    t_data  img;
    img.posX = WINDOW_WIDTH / 2;
    img.posY = WINDOW_HEIGHT / 2;

    int map[mapRows][mapCols] = 
    {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Creating Window and Canvas
    img.mlx = mlx_init();
    img.window = mlx_new_window(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "SOLI DEO GLORIA!");
    img.img = mlx_new_image(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // Setting Hooks
    mlx_key_hook(img.window, move, &img);
    mlx_hook(img.window, 17, 1L<<2, close_window, &img);
    mlx_loop_hook(img.mlx, renderer, &img);
    mlx_loop(img.mlx);
    return (0);
}