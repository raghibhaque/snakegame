
#ifndef SNAKE_H
#define SNAKE_H
#include <stdbool.h>


#define MAX_SNAKE_SIZE 512
#define BoardWidth 40
#define BoardHeight 20
#define MAX_FOOD 10

typedef struct Point
{
    int x;
    int y;
} Point;


typedef enum {
     DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT 
    } Direction;

extern Point snake[MAX_SNAKE_SIZE];
extern int   snake_len;
extern Direction dir, next_dir;
extern Point food;
extern int   score, high_score;
extern bool  running;
extern Point newHead;
extern int *ptr;


void init_game();
void end_game();
void placeFood(int x, int y);
void handle_input();
void update();
void draw();
void addScore(int *ptr);
void resetScore();
void saveHighScore();
void loadHighScore();
void drawBoard();
void gameOverScreen();

#endif