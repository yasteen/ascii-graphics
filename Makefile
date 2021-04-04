FLAGS = -Wall -lncurses

EXES = window free
OBJS = slep
MAIN = main

all: $(EXES)


window: window.c
	gcc window.c slep.c -o main $(FLAGS)

free: free.c
	gcc free.c -o free $(FLAGS)

clean:
	rm -f $(EXES) $(MAIN)

# Don't treat "all" and "clean" as file targets
.PHONY: all clean
