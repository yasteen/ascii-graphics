CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lasciigraphics

TARGETS = test

all: $(TARGETS)

test: test.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGETS)

.PHONY: all clean
