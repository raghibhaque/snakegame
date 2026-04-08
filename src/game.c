#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "snake.h"

Point newHead;


void placeFood(int x, int y){
    food.x = x;
    food.y = y;
}

void update(){
    newHead = snake[0];
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
    
    for(int i = snake_len - 1; i > 0; i--){
        snake[i] = snake[i - 1];
    }
    snake[0] = newHead;
}

void isOnSnake(Point newHead){ // self collision check
        for(int i = 0; i < snake_len; i++){
            if(snake[i].x == newHead.x && snake[i].y == newHead.y){
                running = false;
                return;
            }
        }
    }

void isOnWall(Point newHead){
    if(newHead.x < 0 || newHead.x >= BoardWidth || newHead.y < 0 || newHead.y >= BoardHeight){
        running = false;
        mvprintw(BoardHeight + 1, 0, "Game Over! You hit the wall.");
        refresh();
    }
}
