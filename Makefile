CC=gcc
CFLAGS=-g -Wall
EXEC=ruzzleSolver
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

ruzzleSolver: $(OBJ)
	$(CC) -o bin/$@ $^

ruzzle.o: ../include/display.h

%.o: %.c 
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf src/$(OBJ)

mrproper: clean
	rm -rf bin/$(EXEC)
