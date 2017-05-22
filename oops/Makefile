CC = arm-hisiv300-linux-gcc
CCFLAGS = -g
BIN = oops
OBJ = main.o

$(BIN) : $(OBJ)
	$(CC) $(CCFLAGS) -o oops $(OBJ)

$(OBJ) : main.c
	$(CC) $(CCFLAGS) -c main.c

.PHONY : clean
clean :
	-rm $(BIN) $(OBJ)