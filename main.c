#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>


int main(void){
    initscr();
    noecho();
    curs_set(FALSE);

    printw("Snake game starting");
    refresh();   
    getch();   


    endwin();    // ending ncurses mode
    return 0;
}