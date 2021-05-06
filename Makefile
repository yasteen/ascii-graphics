CC		= gcc
CFLAGS	= -Wall -g
LDFLAGS	= -lncurses -lm
OBJFILES = libasciigraphics.o slep.o graphics2d.o vecmath.o

# Add extra -fPIC flag to implicit rule
%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -fPIC $< -o $@ $(LDFLAGS)

all: $(OBJFILES)

# Create shared file
libasciigraphics.so: $(OBJFILES)
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(LDFLAGS)

# file is saved to /usr/lib.
install: libasciigraphics.so
	cp libasciigraphics.so /usr/lib
	cp asciigraphics.h /usr/include
ifeq (, $(wildcard /usr/include/asciigraphics))
	mkdir /usr/include/asciigraphics
endif
	cp -a asciigraphics/. /usr/include/asciigraphics

uninstall:
ifneq (,$(wildcard /usr/lib/libasciigraphics.so))
	rm /usr/lib/libasciigraphics.so
else
	@echo "The library .so file is not yet installed."
endif
ifneq (,$(wildcard /usr/include/asciigraphics.h))
	rm /usr/include/asciigraphics.h
else
	@echo "The library  .h file is not yet installed."
endif
ifneq (,$(wildcard /usr/include/asciigraphics))
	rm -r /usr/include/asciigraphics
endif

clean:
	rm -f *.o *.so

# Don't treat as file targets
.PHONY: all clean install uninstall
