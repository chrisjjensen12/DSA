CC          = g++ -std=c++11
LD          = g++ 
CFLAG       = -Wall
PROG_NAME1   = BFS
PROG_NAME2   = DFS
PROG_NAME3	= graphs

SRC_DIR     = ./src
BUILD_DIR   = ./build
BIN_DIR     = ./bin

SRC_LIST1 = ./src/BFS.cpp
OBJ_LIST1 = $(BUILD_DIR)/$(notdir $(SRC_LIST1:.cpp=.o))

SRC_LIST2 = ./src/DFS.cpp
OBJ_LIST2 = $(BUILD_DIR)/$(notdir $(SRC_LIST2:.cpp=.o))

SRC_LIST3 = ./src/graphs.cpp
OBJ_LIST3 = $(BUILD_DIR)/$(notdir $(SRC_LIST3:.cpp=.o))

.PHONY: all clean $(PROG_NAME1) BFS_compile $(PROG_NAME2) DFS_compile $(PROG_NAME3) graphs_compile 

all: $(PROG_NAME1) $(PROG_NAME2) $(PROG_NAME3)

BFS_compile: 
	$(CC) -c $(CFLAG) $(SRC_LIST1) -o $(OBJ_LIST1)

$(PROG_NAME1): BFS_compile
	$(LD) $(OBJ_LIST1) -o $(BIN_DIR)/$@

DFS_compile: 
	$(CC) -c $(CFLAG) $(SRC_LIST2) -o $(OBJ_LIST2)

$(PROG_NAME2): DFS_compile
	$(LD) $(OBJ_LIST2) -o $(BIN_DIR)/$@

graphs_compile: 
	$(CC) -c $(CFLAG) $(SRC_LIST3) -o $(OBJ_LIST3)

$(PROG_NAME3): graphs_compile
	$(LD) $(OBJ_LIST3) -o $(BIN_DIR)/$@

clean:
	rm -f $(BIN_DIR)/$(PROG_NAME1) $(BUILD_DIR)/*.o
	rm -f $(BIN_DIR)/$(PROG_NAME2) $(BUILD_DIR)/*.o
	rm -f $(BIN_DIR)/$(PROG_NAME3) $(BUILD_DIR)/*.o