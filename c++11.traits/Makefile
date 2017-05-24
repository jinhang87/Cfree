CC = arm-hisiv300-linux-g++
CCFLAGS = -O2 -s -std=c++11
BIN = c++11.traits
OBJ = main.o test1.o

$(BIN) : $(OBJ)
	$(CC) $(CCFLAGS) -o $(BIN) $(OBJ)

$(OBJ) : main.cpp
	$(CC) $(CCFLAGS) -c main.cpp test1.cpp

.PHONY : clean
clean :
	-rm $(BIN) $(OBJ)