CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -lncurses
TARGET = snake

SRCS = src/main.c src/game.c src/input.c src/render.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c $< -Iinclude -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run