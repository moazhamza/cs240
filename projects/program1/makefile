C_FLAGS=-Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCES = AntHill.cpp Ant.cpp LinkedList.cpp 
PROJECT_NAME = AntFarm
EXECUTABLE = project1

all: $(EXECUTABLE)

$(EXECUTABLE): AntHill.o Ant.o LinkedList.o $(EXECUTABLE).o
	g++ $(C_FLAGS) AntHill.o Ant.o LinkedList.o $(EXECUTABLE).o -o $(EXECUTABLE)

Ant.o: Ant.cpp Ant.h
	g++ -c $(C_FLAGS) Ant.cpp -o Ant.o

AntHill.o: AntHill.cpp AntHill.h
	g++ -c $(C_FLAGS) AntHill.cpp -o AntHill.o

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c $(C_FLAGS) LinkedList.cpp -o LinkedList.o

$(EXECUTABLE).o: $(EXECUTABLE).cpp
	g++ -c $(C_FLAGS) $(EXECUTABLE).cpp -o $(EXECUTABLE).o
run: all
	./$(EXECUTABLE)

checkmem: all
	valgrind ./$(EXECUTABLE) --leak-check=full

clean:
	rm -f *.o $(EXECUTABLE)


