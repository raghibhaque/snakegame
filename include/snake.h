
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
extern int   score, high_score;
extern bool  running;
extern Point newHead;
extern int *ptr;
extern Point foodArray[MAX_FOOD];
extern int   food_count;


void init_game();
void end_game();
void handle_input();
void update();
void draw();
void addScore(int *ptr);
void resetScore();
void saveHighScore();
void loadHighScore();
void drawBoard();
void gameOverScreen();
void placeMultipleFood(int count);
void isOnSnake(Point newHead);
void isOnWall(Point newHead);
#endif