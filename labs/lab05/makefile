C_FLAGS=-Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCES = LinkedList.h Queue.h
PROJECT_NAME = lab05
EXECUTABLE = lab05

all: $(EXECUTABLE)

$(EXECUTABLE): $(EXECUTABLE).o
	g++ $(C_FLAGS) $(EXECUTABLE).o -o $(EXECUTABLE)

$(EXECUTABLE).o: $(EXECUTABLE).cpp LinkedList.h Queue.h
	g++ -c $(C_FLAGS) $(EXECUTABLE).cpp -o $(EXECUTABLE).o

run: all
	./$(EXECUTABLE)

checkmem: all
	valgrind ./$(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)


