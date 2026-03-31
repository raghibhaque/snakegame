#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void init_game(){
    initscr();
    noecho();
    curs_set(FALSE);
}

void end_game(){
    endwin();
}

void placeFood(){
    
}
