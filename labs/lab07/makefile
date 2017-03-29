C_FLAGS=-Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCES = lab7.cpp BSTree.cpp BSTree.h
PROJECT_NAME = lab7
EXECUTABLE = lab7

all: $(EXECUTABLE)

$(EXECUTABLE): $(EXECUTABLE).o BSTree.o
	g++ $(C_FLAGS) $(EXECUTABLE).o BSTree.o -o $(EXECUTABLE)

$(EXECUTABLE).o: $(EXECUTABLE).cpp 
	g++ -c $(C_FLAGS) $(EXECUTABLE).cpp -o $(EXECUTABLE).o

BSTree.o: BSTree.cpp BSTree.h
	g++ -c $(C_FLAGS) BSTree.cpp -o BSTree.o

run: all
	./$(EXECUTABLE)

checkmem: all
	valgrind ./$(EXECUTABLE) 
clean:
	rm -f *.o $(EXECUTABLE)


