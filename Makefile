SRC=main.c

build:
	gcc $(SRC) mlx/libmlx.a -framework OpenGL -framework AppKit
clean:
	rm a.out
