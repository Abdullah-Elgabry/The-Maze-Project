#include "../maze.h"

/**
 * get_line_count - count line num function.
 *
 * @file_string: file pth.
 *
 * Return: 0 or lines num.
 *
 **/

size_t get_line_count(char *file_string)
{
	FILE *maze_file;
	char *line = NULL;
	size_t lines = 0;
	size_t line_len = 0;
	ssize_t read;

	maze_file = fopen(file_string, "r");
	if (maze_file == NULL)
	{
		fprintf(stderr, "File does not exist\n");
		return (0);
	}

	while ((read = getline(&line, &line_len, maze_file)) != -1)
	{
		lines++;
	}
	fclose(maze_file);
	free(line);

	return (lines);
}

/**
 * get_char_count - str counter.
 *
 * @line: spec str.
 *
 * Return: num of char.
 *
 **/
size_t get_char_count(char *line)
{
	size_t char_count = 0;

	while (line[char_count] != '\0')
		char_count++;
	return (char_count);
}

/**
 * plot_grid_points - maze spot init.
 *
 * @maze: [map grid].
 *
 * @play: user dimen.
 *
 * @win: win sentn spot.
 *
 * @cur_char: now reading char.
 *
 * @maze_line: now initializing.
 *
 * @line: now line rendernig.
 *
 * @found_win: Was the win square in the maze found
 **/
void plot_grid_points(char **maze, double_s *play, int_s *win, size_t cur_char,
		      size_t maze_line, char *line, int *found_win)
{
	if (line[cur_char] == 'p')
	{
		play->y = cur_char;
		play->x = maze_line;
		maze[maze_line][cur_char] = '0';
	}
	else if (line[cur_char] == 'w')
	{
		*found_win = 1;
		win->y = cur_char;
		win->x = maze_line;
		maze[maze_line][cur_char] = '0';
	}
	else
	{
		if (line[cur_char] == '0' && *found_win == 0)
		{
			win->y = cur_char;
			win->x = maze_line;
		}
		maze[maze_line][cur_char] = line[cur_char];
	}
}

/**
 * create_map - [map function for initializing].
 *
 * @file_string: map location.
 *
 * @play: user pos.
 *
 * @win: win sentn spot.
 *
 * @map_h: [long for the space].
 *
 * Return: null OR ptr represenataion.
 *
 **/
char **create_map(char *file_string, double_s *play, int_s *win, size_t *map_h)
{
	FILE *maze_file;
	char **maze, *line = NULL;
	ssize_t read = 0;
	size_t line_count, maze_line, char_count, cur_char, bufsize;
	int found_win = 0;

	found_win = 0;
	maze_line = 0;
	line_count = get_line_count(file_string);
	*map_h = line_count;
	if (line_count == 0)
		return (NULL);
	maze = malloc(sizeof(int *) * line_count);
	if (maze == NULL)
		return (NULL);
	maze_file = fopen(file_string, "r");
	if (maze_file == NULL)
		return (NULL);
	read = getline(&line, &bufsize, maze_file);
	while (read != -1)
	{
		char_count = get_char_count(line);
		maze[maze_line] = malloc(sizeof(char) * char_count + 1);
		if (maze == NULL)
			return (NULL);
		for (cur_char = 0; cur_char < char_count; cur_char++)
		{
			plot_grid_points(maze, play, win, cur_char, maze_line, line, &found_win);
		}
		maze_line++;
		read = getline(&line, &bufsize, maze_file);
	}
	fclose(maze_file);
	free(line);
	return (maze);
}
