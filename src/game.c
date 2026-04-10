#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "snake.h"

Point newHead;
int points = 0;
int *ptr = &points;


void placeMultipleFood(int count){
    if(count > MAX_FOOD) count = MAX_FOOD;
    food_count = count;
    for(int i = 0; i < count; i++){
        foodArray[i].x = 1 + rand() % (BoardWidth - 2);
        foodArray[i].y = 1 + rand() % (BoardHeight - 2);
    }
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

    for(int i = 0; i < food_count; i++){
        if(snake[0].x == foodArray[i].x && snake[0].y == foodArray[i].y){
            addScore(ptr);
            snake_len++;
            foodArray[i].x = 1 + rand() % (BoardWidth - 2);
            foodArray[i].y = 1 + rand() % (BoardHeight - 2);
            break;
        }
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
    if(newHead.x <= 0 || newHead.x >= BoardWidth || newHead.y <= 0 || newHead.y >= BoardHeight){
        running = false;
        mvprintw(BoardHeight + 1, 0, "Game Over! You hit the wall.");
        refresh();
    }
}
