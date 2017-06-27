#CC = arm-hisiv300-linux-g++
CC = g++
CCFLAGS = -O2 -s -std=c++11 -Wl,--no-as-needed
LDFLAGS = -lpthread
BIN = test
OBJ = main.o

$(BIN) : $(OBJ)
	$(CC) $(CCFLAGS) $(LDFLAGS) -o $(BIN) $(OBJ)

$(OBJ) : main.cpp
	$(CC) $(CCFLAGS) -c main.cpp

.PHONY : clean
clean :
	-rm $(BIN) $(OBJ)