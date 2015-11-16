CC=gcc
CFLAGS=-g -Wall
EXEC=bin/ruzzleSolver
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)
INC= include/

$(EXEC): $(OBJ)
	$(CC) -o $@ $^
	@echo "\nOn reconstruit $@ a cause de $?"

src/ruzzle.o: $(INC)*.h
src/display.o: $(INC)display.h $(INC)random.h
src/trie.o: $(INC)trie.h
src/solver.o: $(INC)trie.h $(INC)display.h $(INC)solver.h

%.o: %.c 
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf ./$(OBJ)

mrproper: clean
	@rm -rf $(EXEC)

.PHONY:doc

doc:
	doxygen configDoc
