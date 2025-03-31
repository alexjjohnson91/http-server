CC=gcc
CFLAGS=-Wall 

BIN_DIR=bin
TARGET=main

all: make_dirs $(BIN_DIR)/$(TARGET)

make_dirs:
	mkdir -p $(BIN_DIR)

run:
	./$(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): src/main.c
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -rf $(BIN_DIR) 

.PHONY: all make_dirs clean run

