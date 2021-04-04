FLAGS = -Wall -lncurses

EXES = run
OBJS = slep ascii_graphics
MAIN = main

all: $(EXES)


run: run.c
	gcc run.c ascii_graphics.c slep.c -o main $(FLAGS)


clean:
	rm -f $(EXES) $(MAIN)

# Don't treat "all" and "clean" as file targets
.PHONY: all clean
