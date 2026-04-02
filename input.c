#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

void handle_input(){
    int dir = getch();
    switch (dir)
    {
    case 'w':
        next_dir = DIR_UP;
        break;
    case 's':
        next_dir = DIR_DOWN;
        break;
    case 'a':
        next_dir = DIR_LEFT;
        break;
    case 'd': 
        next_dir = DIR_RIGHT;
        break;

    case 'q':
        running = false;
        break;

    default:
        break;
    
    }

    if(next_dir != dir){
        dir = next_dir;
    }
}