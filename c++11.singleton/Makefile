CC = arm-hisiv300-linux-g++
CCFLAGS = -O2 -s -std=c++11
BIN = c++11.singleton
OBJ = main.o

$(BIN) : $(OBJ)
	$(CC) $(CCFLAGS) -o c++11.singleton $(OBJ)

$(OBJ) : main.cpp
	$(CC) $(CCFLAGS) -c main.cpp

.PHONY : clean
clean :
	-rm $(BIN) $(OBJ)