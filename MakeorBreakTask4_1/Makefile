CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g

TARGET = main

all: build

build: $(TARGET)

$(TARGET): main.o other.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o other.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

other.o: other.c
	$(CC) $(CFLAGS) -c other.c

run: build
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
