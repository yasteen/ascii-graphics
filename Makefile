FLAGS = -Wall -g -lncurses

EXES = run
OBJS = slep ascii_graphics
MAIN = main test

all: $(MAIN)


main: run.c slep.c ascii_graphics.c
	gcc run.c ascii_graphics.c slep.c -o main $(FLAGS) -lm

test: test.c ascii_graphics.c
	gcc test.c ascii_graphics.c -o test $(FLAGS)

clean:
	rm -f $(MAIN)

# Don't treat "all" and "clean" as file targets
.PHONY: all clean
