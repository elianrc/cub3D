#include "../cub3d.h"

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int             key_hook(int keycode, t_vars *vars)
{
    if (keycode == ESC)
        exit(1);
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

int             close_win(int keycode, t_vars *vars)
{
    printf("-- CLOSING --\n");
    exit(1);
    return (0);
}

int             enter(int keycode, t_vars *vars)
{
    printf("Hello!\n");
    return (0);
}

int             leave(int keycode, t_vars *vars)
{
    printf("Bye!\n");
    return (0);
}

int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "SOLI DEO GLORIA!");
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<2, close_win, &vars);
    mlx_mouse_hook(vars.win, enter, &vars);
    mlx_mouse_hook(vars.win, leave, &vars);


    mlx_loop(vars.mlx);
} 