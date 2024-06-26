CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: main run clean


main: main.c other.c
	$(CC) $(CFLAGS) -o main main.c other.c

run:
	@-./main

clean:
	rm -f main
