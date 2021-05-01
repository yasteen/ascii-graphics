FLAGS = -Wall -g -lncurses -lm

MAIN = main
OUT = run
TEST = test
DEPS = slep.c ascii_graphics.c vecmath.c engine.c

all: $(OUT)


run: main.c $(DEPS)
	gcc main.c $(DEPS) -o run $(FLAGS)

test: test.c $(DEPS)
	gcc test.c $(DEPS) -o test $(FLAGS)

clean:
	rm -f $(OUT) $(TEST)

# Don't treat "all" and "clean" as file targets
.PHONY: all clean
