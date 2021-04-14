FLAGS = -Wall -g -lncurses

EXES = run
DEPS = slep.c ascii_graphics.c vecmath.c
MAIN = main test

all: $(MAIN)


main: run.c $(DEPS)
	gcc run.c $(DEPS) -o main $(FLAGS) -lm

test: test.c ascii_graphics.c
	gcc test.c $(DEPS) -o test $(FLAGS)

clean:
	rm -f $(MAIN)

# Don't treat "all" and "clean" as file targets
.PHONY: all clean
