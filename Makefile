CC = gcc

CFLAGS = -Wall -Wextra -Iinclude -O2
SRC = $(shell find src -name '*.c')
OBJ = $(SRC:src/%.c=build/%.o)

BIN = build/sclien



all: $(BIN)
	find ./build -type f -name "*.o" -exec rm -f {} +
	

$(BIN): $(OBJ)
	mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@ -lcurl

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@  

clean: 
	rm -rf build

.Phony: all clean

