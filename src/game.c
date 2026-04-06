#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"



void init_game(){
    initscr();
    noecho();
    curs_set(FALSE);
}

void end_game(){
    endwin();
}

void placeFood(){
    food.x = rand() % BoardWidth;
    food.y = rand() % BoardHeight;
}
