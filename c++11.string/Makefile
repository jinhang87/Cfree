#CC = arm-hisiv300-linux-g++
CC = g++
CCFLAGS = -O2 -s -std=c++11
BIN = test
OBJ = main.o

$(BIN) : $(OBJ)
	$(CC) $(CCFLAGS) -o test $(OBJ)

$(OBJ) : main.cpp
	$(CC) $(CCFLAGS) -c main.cpp

.PHONY : clean
clean :
	-rm $(BIN) $(OBJ)