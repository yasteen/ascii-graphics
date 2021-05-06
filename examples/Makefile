CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lasciigraphics

TARGETS = main

all: $(TARGETS)

main: main.c
	$(CC) $(CFLAGS) -o $@ $^ -lm -lncurses $(LDFLAGS)

clean:
	rm -f $(TARGETS)

.PHONY: all clean
