#include <ncurses.h>

int main() {
	int ch;
	initscr();
	keypad(stdscr, TRUE);
	noecho();

	printw("Hello, press any key\n");
	ch = getch();
	printw("Pressed key is: ");
	attron(A_BOLD);
	printw("%c\n", ch);
	attroff(A_BOLD);

	refresh();
	getch();

	endwin();
	return 0;
}
