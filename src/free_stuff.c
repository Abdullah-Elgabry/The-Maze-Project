#include "../maze.h"

/**
 * free_memory -  THIS FUNC FOR freeing up the unused memmory.
 *
 * @instance: drawing inst.
 *
 * @map: rendring the map on.
 *
 * @map_h: map dist.
 *
 **/
void free_memory(SDL_Instance instance, char **map, size_t map_h)
{
	free_map(map, map_h);
	close_SDL(instance);
}

/**
 * free_map - map free function.
 *
 * @map: render map for user.
 *
 * @map_h: map dist
 *
 **/
void free_map(char **map, size_t map_h)
{
	size_t i = 0;

	while (i < map_h)
	{
		free(map[i]);
		i++;
	}
}

/**
 * close_SDL - exit window function
 * @instance: drawing inst.
 **/
void close_SDL(SDL_Instance instance)
{
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
}
