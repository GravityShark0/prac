#include <curses.h>
#include <ncurses.h>
#include <stdlib.h>

void printing();
void moving_and_sleeping();
void colouring();


int main(int argc, char *argv[])
{
    initscr();

    /* addstr("-----------------\n| codedrome.com |\n| ncurses Demo  |\n-----------------\n\n"); */
    /* refresh(); */

    // printing();

    // moving_and_sleeping();

    //colouring();

    WINDOW * win = newwin(10,10,10,10);

    refresh();
    
    box(win, 0, 0);
    wrefresh(win);
    while (true)
    {
        int key = getch();
        if (key == KEY_DOWN) {
            wmove(win, 1, 0);
        }
        else if (key == KEY_RIGHT) {
            wmove(win, 0, 1);
        }
        else if (key == KEY_LEFT) {
            wmove(win, 0, -1);
        }
        else if (key == KEY_UP) {
            wmove(win, -1, 0);
        }
        wrefresh(win);
        refresh();
    }



    addstr("\npress any key to exit...");
    refresh();

    getch();

    endwin();

    return EXIT_SUCCESS;   
}

void printing()
{
    addstr("This was printed using addstr\n\n");
    refresh();

    addstr("The following letter was printed using addch:- ");
    addch('a');
    refresh();

    printw("\n\nThese numbers were printed using printw\n%d\n%f\n", 123, 456.789);
    refresh();
} 

void moving_and_sleeping()
{
    int row = 5;
    int col = 0;

    curs_set(0);

    for(char c = 65; c <= 90; c++)
    {
        move(row++, col++);
        addch(c);
        refresh();
        napms(100);
    }

    row = 5;
    col = 3;

    for(char c = 97; c <= 122; c++)
    {
        mvaddch(row++, col++, c);
        refresh();
        napms(100);
    }

    curs_set(1);

    addch('\n');
} 
