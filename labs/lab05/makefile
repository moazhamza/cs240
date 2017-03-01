C_FLAGS=-Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCES = LinkedList.h Queue.h Card.cpp Card.h Deck.cpp Deck.h lab5.cpp
PROJECT_NAME = lab5
EXECUTABLE = lab5

all: $(EXECUTABLE)

$(EXECUTABLE): $(EXECUTABLE).o Card.o Deck.o
	g++ $(C_FLAGS) $(EXECUTABLE).o Card.o Deck.o -o $(EXECUTABLE)

$(EXECUTABLE).o: $(EXECUTABLE).cpp LinkedList.h Queue.h
	g++ -c $(C_FLAGS) $(EXECUTABLE).cpp -o $(EXECUTABLE).o

Card.o : Card.cpp Card.h
	g++ -c $(C_FLAGS) Card.cpp -o Card.o

Deck.o: Deck.cpp Deck.h
	g++ -c $(C_FLAGS) Deck.cpp -o Deck.o

run: all
	./$(EXECUTABLE)

checkmem: all
	valgrind ./$(EXECUTABLE)

clean:
	rm -f *.o $(EXECUTABLE)


