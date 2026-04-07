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
int points = 0;
int *ptr = &points;


void addScore(int *ptr){
    score += *ptr;
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

    printw("Snake game starting");
    
    dir = DIR_RIGHT;
    next_dir = DIR_RIGHT;
    snake_len = 5;
    for(int i = 0; i < snake_len; i++){
        snake[i].x = 5 - i;
        snake[i].y = 5;
    }

    loadHighScore();

    refresh();   
    getch();   


    int xFood = rand() % BoardWidth;
    int yFood = rand() % BoardHeight;
    food.x = xFood;
    food.y = yFood;

    placeFood(xFood, yFood);


    saveHighScore();
    end_game();
    return 0;
}