C_FLAGS=-Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCES = $(PROJECT_NAME).cpp Ant.cpp lab3.cpp
PROJECT_NAME = AntHill
EXECUTABLE = lab3

all: $(EXECUTABLE)

$(EXECUTABLE): $(PROJECT_NAME).o Ant.o $(EXECUTABLE).o
	g++ $(C_FLAGS) $(PROJECT_NAME).o Ant.o $(EXECUTABLE).o -o $(EXECUTABLE)

$(PROJECT_NAME).o: $(PROJECT_NAME).cpp $(PROJECT_NAME).h
	g++ -c $(C_FLAGS) $(PROJECT_NAME).cpp -o $(PROJECT_NAME).o

Ant.o: Ant.cpp Ant.h
	g++ -c $(C_FLAGS) Ant.cpp -o Ant.o

$(EXECUTABLE).o: lab3.cpp
	g++ -c $(C_FLAGS) $(EXECUTABLE).cpp -o lab3.o

run: all
	./$(EXECUTABLE)

checkmem: all
	valgrind ./$(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)


