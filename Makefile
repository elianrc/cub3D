SRC=main.c

build:
	gcc $(SRC) mlx/libmlx.a -framework OpenGL -framework AppKit
beta:
	gcc $(SRC) mlx_beta/libmlx.dylib -framework OpenGL -framework AppKit

clean:
	rm a.out
