#include "../maze.h"

/**
 * print_win - this function for pop up win msg for user.
 **/
void print_win(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("     \\  /  __   |     |\n");
	printf("      \\/  /  \\  |     |\n");
	printf("      /  |    |      |\n");
	printf("     /    \\__/   \\___/\n\n");
	printf("\\\\      /\\\\      / ======= |\\\\   |\n");
	printf(" \\\\    /  \\\\    /     ||   | \\\\  |\n");
	printf("  \\\\  /    \\\\  /      ||   |  \\\\ |\n");
	printf("   \\\\/      \\\\/    ======= |   \\\\|\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
}

/**
 * check_win - maze win spot.
 *
 * @play: user dirct.
 *
 * @win: msg space.
 *
 * @win_value: checking the msg appears.
 *
 * Return:0 or 1.
 *
 **/
int check_win(double_s play, int_s win, int *win_value)
{
	if ((int) play.x == win.x && (int) play.y == win.y)
	{
		*win_value = 1;
		return (1);
	}
	return (0);
}
