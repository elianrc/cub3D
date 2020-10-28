SRC=main.c

test:
	gcc $(SRC) mlx/libmlx.a -framework OpenGL -framework AppKit

clean:
	rm a.out
