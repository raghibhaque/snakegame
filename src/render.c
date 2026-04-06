#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

void draw(){
    clear();

    mvaddch(food.y, food.x, 'F');

    for(int i = 0; i < snake_len; i++){
        mvaddch(snake[i].y, snake[i].x, 'O');
    }
    
    refresh();
}