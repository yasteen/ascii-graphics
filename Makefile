CC ?= gcc
CFLAGS ?= -Wall -g
LDFLAGS ?= -lncurses -lm

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

TARGET ?= libasciigraphics.so
SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(LDFLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@ $(LDFLAGS)

install:
	make
	mkdir -p /usr/include/asciigraphics
	cp -r ./src/include/* /usr/include/asciigraphics
	cp $(BUILD_DIR)/libasciigraphics.so /usr/lib

uninstall:
	rm -r /usr/include/asciigraphics
	rm /usr/lib/libasciigraphics.so


clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: clean install uninstall
-include $(DEPS)


