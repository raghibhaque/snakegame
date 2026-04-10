#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

void handle_input(){
    int ch = getch();
    switch (ch)
    {
    case 'w':
    case KEY_UP:
        next_dir = DIR_UP;
        break;
    case 's':
    case KEY_DOWN:
        next_dir = DIR_DOWN;
        break;
    case 'a':
    case KEY_LEFT:
        next_dir = DIR_LEFT;
        break;
    case 'd':
    case KEY_RIGHT:
        next_dir = DIR_RIGHT;
        break;

    case 'q':
        running = false;
        break;

    case 'r':
    placeMultipleFood(3);
        break;

    default:
        break;
    
    }

    if(next_dir != dir){
        dir = next_dir;
    }    
}