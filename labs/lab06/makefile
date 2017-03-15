
C_FLAGS=-Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCES = lab6.cpp Sorter.h
PROJECT_NAME = lab6
EXECUTABLE = lab6

all: $(EXECUTABLE)

$(EXECUTABLE): $(EXECUTABLE).o 
	g++ $(C_FLAGS) $(EXECUTABLE).o -o $(EXECUTABLE)

$(EXECUTABLE).o: $(EXECUTABLE).cpp Sorter.h
	g++ -c $(C_FLAGS) $(EXECUTABLE).cpp -o $(EXECUTABLE).o

run: all
	./$(EXECUTABLE)

checkmem: all
	valgrind ./$(EXECUTABLE) 
clean:
	rm -f *.o $(EXECUTABLE)


