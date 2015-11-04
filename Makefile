CC=gcc
CFLAGS=-g -Wall
EXEC=ruzzleSolver
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

ruzzleSolver: $(OBJ)
	$(CC) -o bin/$@ $^

%.o: %.c 
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
