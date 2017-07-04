CC = arm-hisiv300-linux-g++
#CC = g++
CCFLAGS = -O2 -s -std=c++11 -Wl,--no-as-needed
CCFLAGS += -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_{1,2,4}
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
