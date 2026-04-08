#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "snake.h"

Point newHead;
int points = 0;
int *ptr = &points;


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

    if(snake[0].x == food.x && snake[0].y == food.y){
        addScore(ptr);
        snake_len++;
        food.x = rand() % BoardWidth;
        food.y = rand() % BoardHeight;
    }
}

void isOnSnake(Point newHead){ // self collision check
        for(int i = 1; i < snake_len; i++){
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
