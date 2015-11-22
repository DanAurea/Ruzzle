LDFLAGS= -lcunit
EXEC= ../../tests/ruzzleTest
SRC= $(wildcard *.c) 
OBJ= $(SRC:.c=.o) ../random.o

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
	@echo "\nOn reconstruit $@ a cause de $?"

cUnit.o: $(INC)*.h
randomUnit.o: $(INC)randomUnit.h
random.o: $(INC)random.h

%.o: %.c 
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
	@rm -f $(OBJ)

mrproper: clean
	@rm -f $(EXEC)