#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

void draw(){
    clear();

    drawBoard();

    mvaddch(food.y, food.x, 'F');

    for(int i = 0; i < snake_len; i++){
        mvaddch(snake[i].y, snake[i].x, 'O');
    }
    
    refresh();
}

void drawBoard(){
    for(int x = 0; x < BoardWidth; x++){
        mvaddch(0, x, '#');
        mvaddch(BoardHeight - 1, x, '#');
    }
    for(int y = 0; y < BoardHeight; y++){
        mvaddch(y, 0, '#');
        mvaddch(y, BoardWidth - 1, '#');
    }
}