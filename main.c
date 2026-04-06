#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "snake.h"

Point snake[MAX_SNAKE_SIZE];
int   snake_len;
Direction dir, next_dir;
Point food;
int   score, high_score;
bool  running;


void addScore(int points){
    score += points;
    if(score > high_score){
        high_score = score;
    }

}

void resetScore(){
    score = 0;
}

int main(void){
  

    printw("Snake game starting");
    refresh();   
    getch();   


    return 0;
}