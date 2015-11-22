LDFLAGS= -lcunit
EXEC= ../../tests/ruzzleTest
SRC= $(wildcard *.c)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^
	@echo "\nOn reconstruit $@ a cause de $?"

%.o: %.c 
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
	@rm -f $(OBJ)

mrproper: clean
	@rm -f $(EXEC)