C_FLAGS=-Wall -Wextra -DDEBUG -g -pedantic -std=c++14
SOURCES = $(PROJECT_NAME).cpp lab2.cpp
PROJECT_NAME = AntHill

all: lab2

lab2: $(PROJECT_NAME).o lab2.o
	g++ $(C_FLAGS) $(PROJECT_NAME).o lab2.o -o lab2

$(PROJECT_NAME).o: $(PROJECT_NAME).cpp $(PROJECT_NAME).h
	g++ -c $(C_FLAGS) $(PROJECT_NAME).cpp -o $(PROJECT_NAME).o

lab2.o: lab2.cpp
	g++ -c $(C_FLAGS) lab2.cpp -o lab2.o

run: all
	./lab2	

checkmem: all
	valgrind ./lab2	

clean:
	rm -f *.o lab2


