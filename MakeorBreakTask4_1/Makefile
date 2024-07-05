CC=gcc
CFLAGS=

all:   run 
.PHONY: all


build: clean	
	$(CC) $(CFLAGS)  main.c other.c -o main.exe

run: build
	./main.exe

clean:
	rm -rf ./*.exe