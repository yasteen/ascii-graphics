FLAGS = -Wall -g -lncurses -lm

MAIN = main
OBJS = slep ascii_graphics
OUT = run
TEST = test

all: $(MAIN)


main: main.c slep.c ascii_graphics.c
	gcc main.c ascii_graphics.c slep.c -o run $(FLAGS)

test: test.c ascii_graphics.c
	gcc test.c ascii_graphics.c -o test $(FLAGS)

clean:
	rm -f $(OUT) $(TEST)

# Don't treat "all" and "clean" as file targets
.PHONY: all clean
