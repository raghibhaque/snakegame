#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/snake.h"

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

void saveHighScore(){
    FILE *file = fopen("highscore.txt", "w");
    if(file){
        fprintf(file, "%d", high_score);
        fclose(file);
    }
}


void loadHighScore(){
    FILE *file = fopen("highscore.txt", "r");
    if(file){
        fscanf(file, "%d", &high_score);
        fclose(file);
    } else {
        high_score = 0;
    }
}

int main(void){

    loadHighScore();

    printw("Snake game starting");
    refresh();   
    getch();   

    saveHighScore();
    return 0;
}