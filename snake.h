
#ifndef SNAKE_H
#define snake
#include <stdbool.h>


#define MAX_SNAKE_SIZE 512
#define BoardWidth 40
#define BoardHeight 20
#define MAX_FOOD 10

typedef struct Point
{
    int x;
    int y;
};


typedef enum {
     DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT 
    } Direction;

extern Point snake[MAX_SNAKE_SIZE];
extern int   snake_len;
extern Direction dir, next_dir;
extern Point food;
extern int   score, high_score;
extern bool  running;

#endif