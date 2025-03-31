CC=gcc
CFLAGS=-Wall 

TARGET=main

all: $(TARGET)

run:
	./$(TARGET)

$(TARGET): src/main.c
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -f $(TARGET) 

.PHONY: all clean run

