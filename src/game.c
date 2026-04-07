#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"



void init_game(){
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
}

void end_game(){
    endwin();
}

void placeFood(int x, int y){
    food.x = x;
    food.y = y;
}

void update(){
    Point new_Head = snake[0];
    switch (dir)
    {
    case DIR_UP:
        new_Head.y--;
        break;
    case DIR_DOWN:
        new_Head.y++;
        break;
    case DIR_LEFT:
        new_Head.x--;
        break;
    case DIR_RIGHT:
        new_Head.x++;
        break; 
    default:
        break;  
    }


}
