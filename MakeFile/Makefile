CC = gcc

all: preprocessor compiler assembler linker run

.PHONY: all clean

build: preprocessor compiler assembler linker

run:
	@-./a.out

linker:
	@-${CC} main.c -o a.out

assembler:
	@-as main.s -o main.o 

compiler:
	@-${CC} -S main.c 

preprocessor:
	@-${CC} -E main.c

clean:
	@-rm -rf *.exe 
	@-rm -rf *.o 
	@-rm -rf *.s 
	@-rm -rf *.out 
	@-clear 
