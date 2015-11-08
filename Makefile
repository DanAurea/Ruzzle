CC=gcc
CFLAGS=-g -Wall
EXEC=ruzzleSolver
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= ../include/

all: $(EXEC)

ruzzleSolver: $(OBJ)
	$(CC) -o bin/$@ $^

ruzzle.o: $(INC)display.h
display.o: $(INC)display.h $(INC)random.h
trie.o: $(INC)trie.h
solver.o: $(INC)trie.h $(INC)display.h

%.o: %.c 
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf ./$(OBJ)

mrproper: clean
	@rm -rf bin/$(EXEC)
