/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:58:19 by erc               #+#    #+#             */
/*   Updated: 2020/11/04 00:55:14 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int             move(int keycode, t_data *img)
{
    if (keycode == ESC)
    {
        printf("-- CLOSING --\n");
        exit(1);
    }
    else if (keycode == W)
        printf("W\n");
    else if (keycode == A)
        printf("A\n");
    else if (keycode == S)
        printf("S\n");
    else if (keycode == D)
        printf("D\n");
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
    int posX = 320;
    int posY = 320;
    // how do I update the pixel position for every frame before putting it?
    my_mlx_pixel_put(img, posX, posY, RED);
    mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}

/*
** --------------- MAIN -----------------
*/

int             main(void)
{
    t_data  img;

    // Creating Window and Canvas
    img.mlx = mlx_init();
    img.window = mlx_new_window(img.mlx, 640, 480, "SOLI DEO GLORIA!");
    img.img = mlx_new_image(img.mlx, 640, 640);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    // Setting Hooks
    mlx_key_hook(img.window, move, &img);
    mlx_hook(img.window, 17, 1L<<2, close_window, &img);
    mlx_loop_hook(img.mlx, renderer, &img);

    // Present Pixels
    mlx_loop(img.mlx);
} 