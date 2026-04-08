#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

Point newHead;

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
    switch (dir)
    {
    case DIR_UP:
        newHead.y--;
        break;
    case DIR_DOWN:
        newHead.y++;
        break;
    case DIR_LEFT:
        newHead.x--;
        break;
    case DIR_RIGHT:
        newHead.x++;
        break; 
    default:
        break;  
    }
}

    void isOnSnake(Point newHead){ // self collision check
        for(int i = 0; i < snake_len; i++){
            if(snake[i].x == newHead.x && snake[i].y == newHead.y){
                running = false;
                return;
            }
        }
    }
