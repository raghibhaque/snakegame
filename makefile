CC = gcc
CFLAGS = -Wall -Wextra -lncurses
TARGET = snake

SRCS = main.c game.c input.c render.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
    $(CC) -c $< $(CFLAGS)

clean:
    rm -f $(OBJS) $(TARGET)

run: $(TARGET)
    ./$(TARGET)

.PHONY: all clean run