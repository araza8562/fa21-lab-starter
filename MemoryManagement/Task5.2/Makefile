CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJS = main.o other.o
TARGET = main

all: build run clean

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

other.o: other.c header.h
	$(CC) $(CFLAGS) -c other.c

run: build
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
