CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lasciigraphics

TARGETS = main 2d-demo

all: $(TARGETS)

main: main.c
	$(CC) $(CFLAGS) -o $@ $^ -lm -lncurses $(LDFLAGS)

2d-demo: 2d-demo.c
	$(CC) $(CFLAGS) -o $@ $^ -lm -lncurses $(LDFLAGS)

clean:
	rm -f $(TARGETS)

.PHONY: all clean
