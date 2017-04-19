CC = arm-hisiv300-linux-g++
CCFLAGS = -O2 -s -std=c++11
BIN = test
OBJ = main.o test1.o test2_stl.o

$(BIN) : $(OBJ)
	$(CC) $(CCFLAGS) -o test $(OBJ)

$(OBJ) : test1.cpp main.cpp
	$(CC) $(CCFLAGS) -c test1.cpp main.cpp test2_stl.cpp

.PHONY : clean
clean :
	-rm $(BIN) $(OBJ)