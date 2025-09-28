CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2
SRC = $(shell find src -name '*.c')
OBJ = $(SRC:src/%.c=build/%.o)

BIN_DIR = $(HOME)/bin
TARGET = $(BIN_DIR)/sclien

UNAME_S := $(shell uname -s)


ifeq ($(UNAME_S),Linux)
    OS_SUPPORTED = yes
else ifeq ($(UNAME_S),Darwin)
    OS_SUPPORTED = no
else
    OS_SUPPORTED = no
endif

ifeq ($(OS_SUPPORTED),no)
$(error OS not supported: $(UNAME_S))
endif

all: clean $(TARGET)


$(TARGET): $(OBJ)
	@echo "Creating binary at $@"
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lcurl


build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning build directory..."
	rm -rf build

.PHONY: all clean