#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"

SDL_WINDOW* window = NULL;
SDL_RENDERER* renderer = NULL;

int initilize_window() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		fprintf(stderr, "Error initilizinc SDL...\n");
		return FALSE;
	}
	
	window = SDL_CreateWindow(
			NULL,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			SDL_WINDOW_BORDERLESS
			);
	if (!window)
	{
		fprintf(stderr, "Error creating SDL window\n");
		return FALSE;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		fprintf(stderr, "Error in renderer\n");
		return FALSE;
	}

	return TRUE;
}

int main(void)
{	
	initialize_window();

	return (0);
}


