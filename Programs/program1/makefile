C_FLAGS=-Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all: driver

driver: LinkedList.o Ant.o driver.o
	g++ $(C_FLAGS) LinkedList.o driver.o Ant.o -o driver

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c $(C_FLAGS) LinkedList.cpp -o LinkedList.o

Ant.o: Ant.cpp Ant.h
	g++ -c $(C_FLAGS) Ant.cpp -o Ant.o

driver.o: driver.cpp
	g++ -c $(C_FLAGS) driver.cpp -o driver.o

run: driver
	./driver

clean:
	rm -f *.o driver
