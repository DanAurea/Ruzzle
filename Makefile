export CC=gcc
export CFLAGS=-g -Wall
EXEC=bin/ruzzleSolver
SRC= $(wildcard src/*.c)
export OBJ= $(SRC:.c=.o)
export INC= include/

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
	@rm -f $(OBJ)

mrproper: clean
	@rm -f $(EXEC)

.PHONY: doc

doc:
	doxygen configDoc

tests:
	cd src/tests && make

tclean:
	cd src/tests && make clean

tproper:
	cd src/tests && make mrproper