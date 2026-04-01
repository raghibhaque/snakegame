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


int main(void){
  

    printw("Snake game starting");
    refresh();   
    getch();   


    return 0;
}