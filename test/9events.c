#include "mlx/mlx.h"
#include <stdlib.h>

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

int             close_win(int keycode, t_vars *vars)
{
    exit(1); // close this window address
    return 0;
}

int             main(void)
{
    t_vars    vars;

    vars.mlx = mlx_init();

    vars.win = mlx_new_window(vars.mlx, 640, 640, "Soli Deo Gloria!");

    mlx_hook(vars.win, 17, 1L<<2, close_win, &vars);    // when a specific event happens,
                                                        // the parameter function will be called.
    mlx_loop(vars.mlx);
    return 0;
}