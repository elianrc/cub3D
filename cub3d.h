/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:24:26 by erc               #+#    #+#             */
/*   Updated: 2020/11/28 15:07:23 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
**_____ HEADERS ______
*/

# include "mlx/mlx.h"
# include "megalibft/libft/libft.h"
# include "megalibft/gnl/get_next_line.h"
# include "megalibft/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

/*
**______ COLORS _______
*/

# define WHITE	0x00FFFFFF
# define BLACK	0x00000000
# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define YELLOW	0x00FFFF00

/*
**_____  KEYS  _______
*/

# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124

# define MOVE_SPEED 1
# define ROTA_SPEED	5

/*
**____  STRUCTS  ______
*/

typedef	struct		s_data {
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*window;
	void			*img;
}					t_mlx;

typedef	struct		s_player
{
	int				pos_x;
	int				pos_y;
	int				move[6];
	int				color;
}					t_player;

typedef	struct		s_map
{
	int				tilesize;
	int				map_rows;
	int				map_cols;
	int				window_width;
	int				window_height;
	int				floor_color;
	int				wall_color;

	int				size_x;	// the same as window width
	int				size_y; // the same as window height
	

	int				map[11][15]; // part of testing
}					t_map;

typedef struct		s_all
{
	t_data			data;
	t_mlx			mlx;
	t_player		player;
	t_map			map;
}					t_all;

/*
**___  FUNCTIONS  _____
*/

int					ft_init_values(t_all *all);
int					ft_init_mlx(t_all *all);

int					ft_close(void);
int					ft_update(t_all *all);
int					ft_key_pressed(int keycode, t_all *all);
int					ft_key_released(int keycode, t_all *all);
int					ft_move_up_down(t_all *all, int speed);
int					ft_slide_left_right(t_all *all, int speed);

int					ft_render(t_all *all);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
void				draw_line(t_all *all, int x1, int y1,
								int x2, int y2, int color);
void				draw_square(t_all *all, int x, int y, int size, int color);
void				draw_grid(t_all *all, int color);
void				draw_map(t_all *all, int wallcol, int floorcol);
void				draw_player(t_all *all, int pos_x,
								int pos_y, int size, int color);
int					ft_map(t_all *all);
int					ft_analyze_map(t_all *all, char **argv);

#endif
