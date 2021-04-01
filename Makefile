CFLAGS += -Wall -lncurses
EXES += main

all: $(EXES)

main: main.c
	gcc main.c -o main $(CFLAGS)

clean:
	rm -f $(EXES)

# Don't treat "all" and "clean" as file targets
.PHONY: all clean
