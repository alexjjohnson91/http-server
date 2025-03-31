CC=gcc
CFLAGS=-Wall 

all: main

run:
	./main

main: src/main.c
	$(CC) $(CFLAGS) $^ -o $@ 

clean:
	rm -f main 

.PHONY: all clean run

