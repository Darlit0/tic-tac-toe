EXEC = tic-tac-toe

CC = gcc

CFLAGS = -Wall -Wextra -std=c11

OBJ = main.o rules.o display.o

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

clean:
	rm -f $(OBJ) $(EXEC)
